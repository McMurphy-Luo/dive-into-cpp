//
// Created by luojiayi on 4/21/17.
//

#include <iostream>
#include <boost/core/ignore_unused.hpp>
#include <miscellaneous/cpu_time.h>

int main(int argc, char* argv[]){
    using namespace std;
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);
    cout << "This system cpu time tick is " << rookie::CPU_Time::getClockTick() << endl;
    return 0;
}