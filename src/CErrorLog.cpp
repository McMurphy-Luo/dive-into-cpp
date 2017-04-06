//
// Created by luojiayi on 17-4-6.
//

#include "CErrorLog.h"
#include <cstdio>

namespace rookie{
    void CErrorLog::flush(){
        fwrite(buf_.c_str(), sizeof(std::string::value_type), buf_.length(), stderr);
        buf_.clear();
        fflush(stderr);
    };

    CErrorLog::~CErrorLog(){
        flush();
    };
}