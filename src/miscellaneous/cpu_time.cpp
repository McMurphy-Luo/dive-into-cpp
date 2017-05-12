//
// Created by luojiayi on 4/21/17.
//

#include "cpu_time.h"
#include <unistd.h>
#include <logstream/cerr_log.h>

namespace rookie{
    int64_t CPU_Time::getClockTick() {
        long result = sysconf(_SC_CLK_TCK);
        if (result < 0){
            CErrorLog log;
            log << "sysconf error!" << std::endl;
            log.logCStdError();
        }
        return result;
    };
};