//
// Created by luojiayi on 4/23/17.
//

#ifndef ROOKIE_MISCELLANEOUS_PROCESS_LIMITS_H
#define ROOKIE_MISCELLANEOUS_PROCESS_LIMITS_H
#include <cstdint>
#include <string>
#include <sys/resource.h>

namespace rookie{
    class ProcessLimits{
    public:
        enum class LimitType{
            kAS,
            kCORE,
            kCPU,
            kDATA,
            kFSIZE,
            kMEMLOCK,
            kMSGQUEUE,
            kNICE,
            kNOFILE,
            kNPROC,
            kRSS,
            kRTPRIO,
            kRTTIME,
            kSIGPENDING,
            kSTACK
        };
        static int64_t getLimit(LimitType of_which);
        static std::string getLimitDescription(LimitType of_which);
    };
}

#endif //ROOKIE_MISCELLANEOUS_PROCESS_LIMITS_H
