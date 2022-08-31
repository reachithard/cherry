#ifndef _SERVICE_CONF_H_
#define _SERVICE_CONF_H_

struct ServiceConf
{
    bool unique = false;
    uint32_t threadid = 0;
    uint32_t creator = 0;
    int32_t session = 0;
    size_t memlimit = 0;
    std::string type;
    std::string name;
    std::string source;
    std::string params;
};

#endif // _SERVICE_CONF_H_