//
// Created by luojiayi on 17-4-6.
//

#ifndef ROOKIE_LOGSTREAM_CERR_LOG_H
#define ROOKIE_LOGSTREAM_CERR_LOG_H
#include "log_stream.h"
#include <cstdio>

namespace rookie{
    class CErrorLog: public LogStream{
    public:
        CErrorLog():LogStream(){};
        ~CErrorLog();
        void logCStdError();
        void flush();
    };
}

#endif //ROOKIE_LOGSTREAM_CERR_LOG_H
