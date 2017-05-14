//
// Created by luojiayi on 4/15/17.
//

#include "directory.h"
#include <memory>
#include <cstring>
#include <functional>
#include <cerrno>
#include <dirent.h>
#include <sys/stat.h>
#include <logstream/cerr_log.h>

namespace rookie{
// unamed namespace start for static staff of this file
namespace{
    typedef std::unique_ptr<DIR, std::function<void(DIR*)>> dir_handler_t;
    dir_handler_t get_dir_handler(const std::string& path){
        auto result = dir_handler_t(
            opendir(path.c_str()),
            [](DIR* handler) -> void{
                if (handler) {
                    closedir(handler);
                }
            }
        );
        if (!result) {
            CErrorLog log;
            log << "open directory error;" << std::endl;
            log.logCStdError();
        }
        return result;
    };
}
// unamed namespace end

    bool isDirectory(const std::string &path) {
        struct stat buf;
        if (stat(path.c_str(), &buf) != 0){
            CErrorLog log;
            log << "stat error!" << std::endl;
            log.logCStdError();
            return false;
        }
        return S_ISDIR(buf.st_mode);
    };

    bool Directory::exists() const{
        return isDirectory(path_);
    };

    std::vector<std::shared_ptr<File>> Directory::children() const{
        typedef std::vector<std::shared_ptr<File>> result_t;

        auto dir_handler = get_dir_handler(path_);
        if (!dir_handler){
            return result_t();
        }
        result_t result;
        dirent* dir_read;

        errno = 0;
        while((dir_read = readdir(dir_handler.get())) != nullptr){
            if (std::strcmp(dir_read->d_name, ".") == 0
                    || std::strcmp(dir_read->d_name, "..") == 0){
                continue;
            }
            std::string child_path = path_ + "/" + dir_read->d_name;
            if (isRegularFile(child_path)){
                result.push_back( std::make_shared<File>(child_path) );
                continue;
            }
            if (isDirectory(child_path)){
                result.push_back( std::make_shared<Directory>(child_path) );
                continue;
            }
        }
        if (errno != 0){
            CErrorLog log;
            log << "readdir error!" << std::endl;
            log.logCStdError();
        }
        return result;
    };
}
