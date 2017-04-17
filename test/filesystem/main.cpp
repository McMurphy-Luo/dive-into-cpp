//
// Created by luojiayi on 4/15/17.
//
#include <iostream>
#include <string>
#include <vector>
#include <boost/core/ignore_unused.hpp>
#include <filesystem/Directory.h>

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);
    std::cout << "hello world!" << std::endl;
    rookie::Directory directory("/home/luojiayi");

    auto children = directory.children();

    for (auto i : children){
        std::cout << i->getPath() << std::endl;
    }
    return 0;
}