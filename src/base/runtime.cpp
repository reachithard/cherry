#include "runtime.h"

#include <iostream>

bool Runtime::CheckFile(const std::string &file)
{
    // 检验当前文件的父亲级别或者当前目录是否有./conf/*.conf文件
    // 先从当前目录查找
    namespace fs = std::filesystem;
    auto p = fs::current_path();
    if (fs::exists(p / "conf"))
    {
        runPath = p.generic_string();
        std::cout << "set run path:" << runPath << std::endl;
        return true;
    }

    if (fs::exists(p / "../conf"))
    {
        p = p.parent_path();
        std::cout << "set run path:" << runPath << std::endl;
        runPath = p.generic_string();
        return true;
    }
    return false;
}