//
// Created by luojiayi on 4/23/17.
//
#include <iostream>
#include <miscellaneous/process_limits.h>
#include <boost/core/ignore_unused.hpp>

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);
    using rookie::ProcessLimits;

    std::cout << ProcessLimits::getLimitDescription(ProcessLimits::LimitType::kAS) << std::endl;
}