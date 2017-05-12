//
// Created by luojiayi on 4/23/17.
//

#include "process_limits.h"
#include <memory>
#include <map>
#include <logstream/cerr_log.h>

namespace rookie{
// unamed namespace start for this file static staff
// all rlimit description copy from linux man page
// http://man7.org/linux/man-pages/man2/setrlimit.2.html
namespace{
    typedef std::map<ProcessLimits::LimitType, std::string> limit_description_map_t;
    limit_description_map_t *limit_description_map = nullptr;
    const limit_description_map_t *getLimitDescriptionMap(){
        if (limit_description_map) return limit_description_map;
        limit_description_map = new limit_description_map_t;
        limit_description_map->emplace(
            ProcessLimits::LimitType::kAS,
            "Maximum size of the process's virtual memory (address space) in bytes."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kCORE,
            "Maximum size of a core file (see core(5)) that the process may dump."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kCPU,
            "On the amount of CPU time that the process can consume In seconds."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kDATA,
            "Maximum size of the process's data segment (initialized data, uninitialized data, and heap)."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kFSIZE,
            "Maximum size of files that the process may create."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kMEMLOCK,
            "Maximum number of bytes of memory that may be locked into RAM."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kMSGQUEUE,
            "The number of bytes that can be allocated"
            " for POSIX message queues for the real user ID of the calling"
            " process."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kNICE,
            "This specifies a ceiling to which the process's nice value can be raised using setpriority(2) or nice(2)."
        );limit_description_map->emplace(
            ProcessLimits::LimitType::kNOFILE,
            "This specifies a value one greater than the maximum file descriptor number that can be opened by this process."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kNPROC,
            "The maximum number of processes (or, more precisely on Linux, threads)"
            " that can be created for the real user ID of"
            " the calling process."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kRSS,
            "This is a limit (in bytes) on the process's resident set (the number of virtual pages resident in RAM)."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kRTPRIO,
            "This specifies a ceiling on the real-time priority that may be set"
            " for this process using sched_setscheduler(2) and"
            " sched_setparam(2)."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kRTTIME,
            "This is a limit (in microseconds) on the amount of CPU time"
            " that a process scheduled under a real-time scheduling policy"
            " may consume without making a blocking system call."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kSIGPENDING,
            "This is a limit on the number of signals that may be queued for the real user ID of the calling process."
            " Both standard and real-time signals are counted for the purpose of checking this limit."
        );
        limit_description_map->emplace(
            ProcessLimits::LimitType::kSTACK,
            "This is the maximum size of the process stack, in bytes. Upon reaching this limit, a SIGSEGV signal is generated."
        );

        return limit_description_map;
    };
}
//unamed namespace end

    std::string ProcessLimits::getLimitDescription(LimitType of_which) {
        const limit_description_map_t *limit_description_map = getLimitDescriptionMap();
        const std::string &stored_description = limit_description_map->at(of_which);
        return stored_description;
    }

    int64_t ProcessLimits::getLimit(LimitType of_which) {
        struct rlimit limit;
        int64_t result;
        int sys_call_result;

        switch (of_which) {
            case LimitType::kAS:
                sys_call_result = getrlimit(RLIMIT_AS, &limit);
                break;
            case LimitType::kCORE:
                sys_call_result = getrlimit(RLIMIT_CORE, &limit);
                break;
            case LimitType::kCPU:
                sys_call_result = getrlimit(RLIMIT_CPU, &limit);
                break;
            case LimitType::kDATA:
                sys_call_result = getrlimit(RLIMIT_DATA, &limit);
                break;
            case LimitType::kFSIZE:
                sys_call_result = getrlimit(RLIMIT_FSIZE, &limit);
                break;
            case LimitType::kMEMLOCK:
                sys_call_result = getrlimit(RLIMIT_MEMLOCK, &limit);
                break;
            case LimitType::kMSGQUEUE:
                sys_call_result = getrlimit(RLIMIT_MSGQUEUE, &limit);
                break;
            case LimitType::kNICE:
                sys_call_result = getrlimit(RLIMIT_NICE, &limit);
                break;
            case LimitType::kNOFILE:
                sys_call_result = getrlimit(RLIMIT_NOFILE, &limit);
                break;
            case LimitType::kNPROC:
                sys_call_result = getrlimit(RLIMIT_NPROC, &limit);
                break;
            case LimitType::kRSS:
                sys_call_result = getrlimit(RLIMIT_RSS, &limit);
                break;
            case LimitType::kRTPRIO:
                sys_call_result = getrlimit(RLIMIT_RTPRIO, &limit);
                break;
            case LimitType::kRTTIME:
                sys_call_result = getrlimit(RLIMIT_RTTIME, &limit);
                break;
            case LimitType::kSIGPENDING:
                sys_call_result = getrlimit(RLIMIT_SIGPENDING, &limit);
                break;
            case LimitType::kSTACK:
                sys_call_result = getrlimit(RLIMIT_STACK, &limit);
                break;
        }
        if (sys_call_result < 0){
            CErrorLog log;
            log << "getrlimit call error!" << std::endl;
            log.logCStdError();
        }
        result = limit.rlim_cur;
        return result;
    }
};
