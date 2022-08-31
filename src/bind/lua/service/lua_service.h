#ifndef _LUA_SERVICE_H_
#define _LUA_SERVICE_H_

#include <numeric>
#include <limits>

#include "service.h"

class LuaService final : public Service
{
public:
    LuaService() {}

    ~LuaService() {}

private:
    bool Init(const ServiceConf &conf) override {

    }

    void Dispatch(class Message *msg) override {

    }

    static void *lalloc(void *ud, void *ptr, size_t osize, size_t nsize);

public:
    size_t mem = 0;
    size_t mem_limit = std::numeric_limits<size_t>::max();
    size_t mem_report = 8 * 1024 * 1024;

    // static lua_service *get(lua_State *L);

    // static int set_callback(lua_State *L);

private:

};

#endif // _LUA_SERVICE_H_