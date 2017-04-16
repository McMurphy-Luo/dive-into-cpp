//
// Created by luojiayi on 4/15/17.
//

#include "Directory.h"
#include <cerrno>
#include <dirent.h>
#include <sys/stat.h>
#include <logstream/CErrorLog.h>

namespace rookie{

    namespace{
        DIR* get_dir_handler(std::string& path){
            DIR* dir_handler = opendir(path.c_str());
            if (dir_handler) {
                return dir_handler;
            }
            CErrorLog log;
            log << "open directory error;" << CErrorLog::endl;
            log.logCStdError();
            return nullptr;
        };
    }
    bool Directory::exists(){
        struct stat buf;
        int result = stat(path_.c_str(), &buf);
        CErrorLog log;
        if (result != -1){
            return S_ISDIR(buf.st_mode);
        }
        log << "stat error!" << CErrorLog::endl;
        log.logCStdError();
        return false;
    };

    std::vector<std::string> Directory::children(){
        typedef std::vector<std::string> result_t;
        CErrorLog log;

        DIR* dir_handler = get_dir_handler(path_);

        if (!dir_handler){
            return result_t();
        }
        result_t result;
        dirent* dir_read;
        errno = 0;
        while((dir_read = readdir(dir_handler)) != nullptr){
            result.push_back(std::string(dir_read->d_name));
        }
        if (errno != 0){
            log.logCStdError();
        }
        closedir(dir_handler);
        return result;
    };

    std::vector<File> Directory::getChildFiles() {
        using result_t = std::vector<File>

        DIR* dir_handler = get_dir_handler(path_);
        if (!dir_handler){
            return result_t();
        }
        result_t result();

        dirent* dir_read;
        errno = 0;
        while( (dir_read = readdir(dir_handler)) != nullptr ){

        }

    };

    std::vector<Directory> Directory::getChildDirectories() {

    };
}
