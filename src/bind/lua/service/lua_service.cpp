#include "lua_service.h"

bool LuaService::Init(const ServiceConf &conf)
{
    // memLimit = conf.memlimit;
    // name_ = conf.name;

    // lua_State *L = lua_.get();

    // lua_gc(L, LUA_GCSTOP, 0);
    // lua_gc(L, LUA_GCGEN, 0, 0);

    // std::string initialize_string;
    // auto lua_path = server_->get_env("PATH");
    // if (lua_path)
    //     initialize_string.append(*lua_path);
    // initialize_string.append(conf.params);

    // lua_pushcfunction(L, traceback);
    // int trace_fn = lua_gettop(L);

    // lua_pushcfunction(L, protect_init);
    // lua_pushlightuserdata(L, (void *)conf.source.data());
    // lua_pushlightuserdata(L, initialize_string.data());

    // if (lua_pcall(L, 2, LUA_MULTRET, trace_fn) != LUA_OK || lua_gettop(L) > 1)
    // {
    //     CONSOLE_ERROR(logger(), "new_service lua_error:\n%s.", lua_tostring(L, -1));
    //     return false;
    // }

    // lua_pop(L, 1);

    // if (unique_ && !server_->set_unique_service(name_, id_))
    // {
    //     CONSOLE_ERROR(logger(), "duplicate unique service name '%s'.", name_.data());
    //     return false;
    // }

    // lua_gc(L, LUA_GCRESTART, 0);

    // assert(lua_gettop(L) == 0);

    // ok_ = true;

    // return ok_;
}