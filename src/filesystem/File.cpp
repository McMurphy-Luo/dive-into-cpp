//
// Created by luojiayi on 4/15/17.
//

#include "File.h"
#include <sys/stat.h>
#include <logstream/CErrorLog.h>

namespace rookie{
    bool File::isRegularFile(const std::string &path) {
        struct stat buf;
        if (stat(path.c_str(), &buf) != 0){
            CErrorLog log;
            log << "stat error!" << CErrorLog::endl;
            log.logCStdError();
            return false;
        }
        return S_ISREG(buf.st_mode);
    };

    bool File::exists() {
        return isRegularFile(path_);
    };
}