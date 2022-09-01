#ifndef _INIT_SERVICE_H_
#define _INIT_SERVICE_H_

#include <fstream>
#include <vector>

#include "yyjson.h"

#include "singleton.h"
#include "init_conf.h"

class InitService final : public Singleton<InitService> {
    friend class Singleton;
public:
    virtual ~InitService() {

    }

    std::unique_ptr<InitConfT> Parse(const std::string &file);

private:
    std::unique_ptr<InitConfT> ParseConf(const char *buffer, size_t length);
protected : 
    InitService() = default;
};

#endif // _INIT_SERVICE_H_