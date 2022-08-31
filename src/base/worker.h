#ifndef _WORKER_H_
#define _WORKER_H_

#include <atomic>
#include <memory>

#include "nocopy.h"
#include "service_conf.h"

class Worker : public Nocopy
{
private:
    /* data */
    static constexpr uint32_t MAX_SERVICE = 0xFFFFFF;
public:
    Worker(const std::string &v) : name(v){

    }
    ~Worker() {
        
    }

    void Run() {

    }

    void RemoveService(uint32_t serviceid, uint32_t sender, uint32_t sessionid) {
        // TODO
    }

    uint32_t GetWorkId() const {
        return workerid;
    }

    void NewService(std::unique_ptr<ServiceConf> conf) {
        do
        {
            size_t counter = 0;
            uint32_t serviceid = 0;
            do
            {
                if (counter >= MAX_SERVICE)
                {
                    serviceid = 0;
                    break;
                }

                ++nextid;
                if (nextid == MAX_SERVICE)
                {
                    nextid = 1;
                }
                serviceid = nextid | (GetWorkId() << 24);
                ++counter;
            } while (services.find(serviceid) != services.end());

            if (serviceid == 0)
            {
                break;
            }

            auto s = Singleton<Server>::Get().MakeService(conf->type);
            s->SetId(serviceid);
            s->SetUnique(conf->unique);
            s->SetWorker(this);

            if (!s->Init(*conf))
            {
                // TODO 如果启动bootstrap失败 则关闭
                // if (serviceid == 7)
                // {
                //     server_->stop(-1);
                // }
                break;
            }
            s->SetOk(true);
            services.emplace(serviceid, std::move(s));

            if (0 != conf->session)
            {
                // TODO
                // server_->response(conf->creator, std::string_view{}, std::to_string(serviceid), conf->session);
            }
            return;
        } while (false);

        count.fetch_sub(1, std::memory_order_release);
        if (services.empty())
        {
            SetShared(true);
        }

        if (0 != conf->session)
        {
            // TODO 进行修改
            // server_->response(conf->creator, std::string_view{}, "0"sv, conf->session);
        }
    }

    void Send(class message &&msg) {

    }

    void SetShared(bool v) {
        shared.store(v, std::memory_order_release);
    }

    bool GetShared() const {
        bool ret = shared.load(std::memory_order_acquire);
        return ret;
    }

    uint32_t GetCount() const {
        uint32_t tmp = count.load(std::memory_order_acquire);
        return tmp;
    }

    // TODO
    // intptr_t make_prefab(moon::buffer_ptr_t buf);

    // bool send_prefab(uint32_t sender, uint32_t receiver, intptr_t prefabid, std::string_view header, int32_t sessionid, uint8_t type) const;

    // moon::socket &socket()
    // {
    //     return *socket_;
    // }

    uint32_t Alive() {
        // TODO
    }

private:

    void Stop();

    void Wait();

private:
    // void HandleOne(service *&ser, message &&msg);

    Service *FindService(uint32_t serviceid) const {
        auto it = services.find(serviceid);
        if (it != services.end()) {
            return it->second.get();
        }
        return nullptr;
    }

private:
    std::string name;
    std::atomic_bool shared{true};
    std::atomic_uint32_t count{0};
    std::atomic_uint32_t mqsize{0};
    uint32_t nextid = 0;
    uint32_t workerid = 0;
    uint32_t version = 0;
    double cpucost = 0.0;
    std::thread thread;
    std::unordered_map<uint32_t, std::unique_ptr<Service>> services;
};



#endif // _WORKER_H_