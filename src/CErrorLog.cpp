//
// Created by luojiayi on 17-4-6.
//

#include "CErrorLog.h"
#include <cstdio>
#include <cerrno>
#include <cstring>

namespace rookie{
    void CErrorLog::flush(){
        fwrite(buf_.c_str(), sizeof(std::string::value_type), buf_.length(), stderr);
        buf_.clear();
        fflush(stderr);
    };

    void CErrorLog::logCStdError(){
        this->operator<<( "error number this " );
        this->operator<<( errno );
        this->operator<<( "; error string is " );
        this->operator<<( "\"" );
        this->operator<<(std::strerror(errno));
        this->operator<<( "\"" );
        this->operator<<( ";" );
        this->operator<<( CErrorLog::endl );
    };

    CErrorLog::~CErrorLog(){
        flush();
    };
}