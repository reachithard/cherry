#ifndef _INIT_CONF_H_
#define _INIT_CONF_H_

#include <string>
#include <vector>
#include <memory>

typedef struct InitConfItems
{
    std::string type;
    std::string bootstrap;
} InitConfItemT;

typedef struct InitConfs {
    uint32_t theadCnt = 8;
    std::string logfile;
    bool console = true;
    std::string logLevel;
    std::vector<std::unique_ptr<InitConfItemT>> items;
} InitConfT;

#endif // _INIT_CONF_H_