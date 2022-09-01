#ifndef _SERVER_H_
#define _SERVER_H_

#include <cstdint>
#include <string>
#include <thread>
#include <unordered_map>

#include "singleton.h"
#include "init_service.h"
#include "logger.hpp"
#include "service.h"
#include "lua_service.h"
#include "worker.h"

namespace Log {
static std::unordered_map<std::string, spdlog::level::level_enum> g_logLevel =
    std::unordered_map<std::string, spdlog::level::level_enum>{{"debug", spdlog::level::debug}, {"info", spdlog::level::info},
        {"warn", spdlog::level::warn}, {"err", spdlog::level::err}, {"critical", spdlog::level::critical}};
}

class Server final : public Singleton<Server>
{
private:
    /* data */
public:
    Server(/* args */) {}
    ~Server() {}

    int32_t Init(const std::string &conf) {
        namespace fs = std::filesystem;
        std::unique_ptr<InitConfT> ptr = Singleton<InitService>::Get().Parse(conf);

        std::string logfile = ptr->logfile.empty() ? "./logs/cherry.log" : ptr->logfile;
        Singleton<Logger>::Get().Init(logfile, ptr->console);
        if (Log::g_logLevel.find(ptr->logLevel) != Log::g_logLevel.end()) {
            Singleton<Logger>::Get().SetLevel(Log::g_logLevel[ptr->logLevel]);
        } else {
            Singleton<Logger>::Get().SetLevel(spdlog::level::trace);
        }

        RegisterServiceType();

        uint32_t thCnt = ptr->theadCnt == 0 ? std::thread::hardware_concurrency() : ptr->theadCnt;
        for (uint32_t idx = 0; idx < thCnt; idx++) {
            workers.emplace_back(std::make_unique<Worker>(std::string("worker") + std::to_string(idx)));

            // TODO 加上定时器
        }

        for (uint32_t idx = 0; idx < workers.size(); idx++) {
            workers[idx]->Run();
        }

        // 进行bootstrap启动
        for (uint32_t idx = 0; idx < ptr->items.size(); idx++) {
            std::unique_ptr<ServiceConf> confPtr = std::make_unique<ServiceConf>();
            confPtr->type = ptr->items[idx]->type;
            confPtr->name = "bootstrap";
            confPtr->source = fs::path(ptr->items[idx]->bootstrap).filename().string();
            confPtr->memlimit = std::numeric_limits<size_t>::max();
            // new service
            NewService(std::move(confPtr));
            break; // 只启动一个进行bootstrap启动
        }

        return 0;
    }

    int32_t Run() {
        while (serverRun)
        {
            /* code */
        }
        return 0;
    }

    Worker *NextWorker()
    {
        uint32_t min_count = std::numeric_limits<uint32_t>::max();
        uint32_t min_count_workerid = 0;
        for (const auto &w : workers)
        {
            auto n = w->GetCount();
            if (w->GetShared() && n < min_count)
            {
                min_count = n;
                min_count_workerid = w->GetWorkId();
            }
        }

        if (min_count_workerid == 0)
        {
            min_count = std::numeric_limits<uint32_t>::max();
            for (const auto &w : workers)
            {
                auto n = w->GetCount();
                if (n < min_count)
                {
                    min_count = n;
                    min_count_workerid = w->GetWorkId();
                }
            }
        }
        return workers[min_count_workerid - 1].get();
    }

    Worker *GetWorker(uint32_t workerid, uint32_t serviceid = 0) const
    {
        if (workerid == 0)
        {
            workerid = WorkerId(serviceid);
        }

        if ((workerid <= 0 || workerid > static_cast<uint32_t>(workers.size())))
        {
            return nullptr;
        }

        --workerid;
        return workers[workerid].get();
    }

    void NewService(std::unique_ptr<ServiceConf> conf)
    {
        Worker *w = GetWorker(conf->threadid);
        if (nullptr != w)
        {
            w->SetShared(false);
        }
        else
        {
            w = NextWorker();
        }
        w->NewService(std::move(conf));
    }

    static uint32_t WorkerId(uint32_t serviceid)
    {
        return ((serviceid >> 24) & 0xFF);
    }

    std::unique_ptr<Service> MakeService(const std::string &type) {
        auto iter = serviceType.find(type);
        if (iter != serviceType.end())
        {
            return iter->second();
        }
        return nullptr;
    }

private:
    void RegisterServiceType() {
        // serviceType.emplace("lua", []() -> std::unique_ptr<Service> { return std::make_unique<LuaService>(); });
    }
    std::vector<std::unique_ptr<Worker>> workers;
    std::unordered_map<std::string, std::function<std::unique_ptr<Service>()>> serviceType;
    bool serverRun = true;
};

#endif // _SERVER_H_