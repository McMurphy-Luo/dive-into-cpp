//
// Created by luojiayi on 4/21/17.
//

#ifndef ROOKIE_MISCELLANEOUS_TIME_H
#define ROOKIE_MISCELLANEOUS_TIME_H
#include <cstdint>

namespace rookie{

    class CPU_Time{
    public:
        static int64_t getClockTick();
    };
}

#endif //ROOKIE_MISCELLANEOUS_TIME_H