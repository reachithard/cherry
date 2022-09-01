#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <string>
#include <filesystem>

#include "singleton.h"
#include "logger.hpp"

class Runtime final : public Singleton<Runtime> {
public:
    bool CheckFile(const std::string &file);

private:
    std::string runPath;
};

#endif // _RUNTIME_H_