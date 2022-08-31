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

    std::unique_ptr<InitConfT> Parse(const std::string &file) {
        std::unique_ptr<InitConfT> ptr = nullptr;
        // 读取文件 然后解析
        std::ifstream ifs(file);
        // get the size of file
        ifs.seekg(0, std::ios::end);
        std::streampos length = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        std::vector<char> buffer(length);
        if (ifs.read(buffer.data(), length))
        {
            // process
            ptr = ParseConf(buffer.data(), length);
        }
        return ptr;
    }

private:
    std::unique_ptr<InitConfT> ParseConf(const char *buffer, size_t length) {
        std::unique_ptr<InitConfT> ptr = std::make_unique<InitConfT>();
        // Read JSON and get root
        yyjson_doc *doc = yyjson_read(buffer, length, 0);
        yyjson_val *root = yyjson_doc_get_root(doc);
        if (root == nullptr) {
            yyjson_doc_free(doc);
            return ptr;
        }

        yyjson_val *theadCnt = yyjson_obj_get(root, "theadCnt");
        ptr->theadCnt = yyjson_get_int(theadCnt);

        yyjson_val *logfile = yyjson_obj_get(root, "logfile");
        ptr->logfile = yyjson_get_str(logfile);

        yyjson_val *console = yyjson_obj_get(root, "console");
        ptr->console = yyjson_get_bool(console);

        yyjson_val *logLevel = yyjson_obj_get(root, "logLevel");
        ptr->logLevel = yyjson_get_str(logLevel);

        // Get root["hits"], iterate over the array
        yyjson_val *items = yyjson_obj_get(root, "items");
        size_t idx, max;
        yyjson_val *item;
        yyjson_arr_foreach(items, idx, max, item)
        {
            // printf("hit%d: %d\n", (int)idx, (int)yyjson_get_int(hit));
            std::unique_ptr<InitConfItemT> itemConf = std::make_unique<InitConfItemT>();

            yyjson_val *type = yyjson_obj_get(item, "type");
            itemConf->type = yyjson_get_str(type);

            yyjson_val *bootstrap = yyjson_obj_get(item, "bootstrap");
            itemConf->bootstrap = yyjson_get_str(bootstrap);
        }

        // Free the doc
        yyjson_doc_free(doc);
        return ptr;
    }

protected : 
    InitService() = default;
};

#endif // _INIT_SERVICE_H_