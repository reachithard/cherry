#include <iostream>
#include <exception>
#include <filesystem>

#include "runtime.h"
#include "server.h"

int main(int argc, char** argv) {
    namespace fs = std::filesystem;
    try {
        int32_t arg = 1;
        std::string conf;
        if (argc < arg) {
            conf = "./conf/init.json";
        } else {
            conf = std::string(argv[1]);
        }

        if (!Singleton<Runtime>::Get().CheckFile(conf)) {
            std::cerr << "please run with conf" << std::endl;
            return -1;
        }

        // 其余参数无效
        if (Singleton<Server>::Get().Init(conf) != 0) {
            return -1;
        }

        if (Singleton<Server>::Get().Run() != 0) {
            return -1;
        }

        return 0;
    } catch (std::exception &e) {
        std::cerr << "server run error" << e.what() << std::endl;
    }
    return -1;
}