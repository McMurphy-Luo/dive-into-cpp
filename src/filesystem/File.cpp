//
// Created by luojiayi on 4/15/17.
//

#include "File.h"
#include <unistd.h>
#include <logstream/CErrorLog.h>

namespace rookie{
    bool File::exists() {
        int test_result = access(path_.c_str(), F_OK);
        if (test_result != -1)
        {
            return true;
        }
        CErrorLog log;
        log.logCStdError();
        return false;
    };
}