#ifndef _SERVICE_H_
#define _SERVICE_H_

#include <cstdint>
#include <string>

#include "nocopy.h"
#include "worker.h"
#include "service_conf.h"

class Service : public Nocopy
{
private:
    /* data */
public:
    Service(/* args */) = default;
    virtual ~Service() {

    }

    uint32_t GetId() const {
        return id;
    }

    const std::string& GetName() const {
        return name;
    }

    void SetName(const std::string &inname) {
        name = inname;
    }

    void SetWorker(Worker* w) {
        worker = w;
    }

    Worker *GetWorker() const {
        return worker;
    }

    bool IsUnique() const {
        return unique;
    }

    bool IsOk() const {
        return ok;
    }

    bool SetOk(bool o) {
        ok = o;
    }

    double GetCpu() {
        double v = cpu;
        cpu = 0;
        return v;
    }

    void SetUnique(bool v)
    {
        unique = v;
    }

    void SetId(uint32_t v)
    {
        id = v;
    }

public:
    // do something
    virtual bool Init(const ServiceConf &conf) = 0;

    virtual void Dispatch(class Message* msg) = 0;

protected:
    void AddCpu(double v)
    {
        cpu += v;
    }

protected:
    bool ok = false;
    bool unique = false;
    uint32_t id = 0;
    Worker *worker;
    double cpu = 0.0; //
    std::string name;
};


#endif // _SERVICE_H_