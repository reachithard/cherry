#include "worker.h"

#include "server.h"

void Worker::RemoveService(uint32_t serviceid, uint32_t sender, uint32_t sessionid)
{
    // TODO
}

uint32_t Worker::GetWorkId() const
{
    return workerid;
}

void Worker::NewService(std::unique_ptr<ServiceConf> conf)
{
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

        // 这里多态去调用服务的init
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