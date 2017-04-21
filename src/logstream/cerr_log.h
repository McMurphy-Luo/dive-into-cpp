//
// Created by luojiayi on 17-4-6.
//

#ifndef HELLO_CERRORLOG_H
#define HELLO_CERRORLOG_H
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

#endif //HELLO_CERRORLOG_H
