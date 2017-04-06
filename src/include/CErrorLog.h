//
// Created by luojiayi on 17-4-6.
//

#ifndef HELLO_CERRORLOG_H
#define HELLO_CERRORLOG_H
#include "LogStream.h"
#include <cstdio>

namespace rookie{
    class CErrorLog: public LogStream{
    public:
        CErrorLog():LogStream(){};
        ~CErrorLog();
        void flush();
    };
}

#endif //HELLO_CERRORLOG_H
