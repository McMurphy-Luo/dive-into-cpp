//
// Created by luojiayi on 4/15/17.
//
#include <iostream>
#include <string>
#include <vector>
#include <filesystem/Directory.h>

int main(int argc, char* argv[]){
    std::cout << "hello world!" << std::endl;
    rookie::Directory directory("/home/luojiayi");

    std::vector<std::string> children = directory.children();

    for (auto i : children){
        std::cout << i << std::endl;
    }
    return 0;
}