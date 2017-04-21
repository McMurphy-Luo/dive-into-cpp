//
// Created by luojiayi on 4/21/17.
//

#ifndef HELLO_TIME_H
#define HELLO_TIME_H
#include <cstdint>

namespace rookie{

    class CPU_Time{
    public:
        static int64_t getClockTick();
    };
}

#endif //HELLO_TIME_H