//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_DIRECTORY_H
#define HELLO_DIRECTORY_H

#include <string>
#include <vector>
#include "File.h"

namespace rookie{
    class Directory{
    public:
        explicit Directory(std::string path):path_(path){};
        bool exists();
        std::string getPath() { return path_; };
        std::vector<std::string> children();
        std::vector<File> getChildFiles();
        std::vector<Directory> getChildDirectories();

    private:
        std::string path_;
    };
}

#endif //HELLO_DIRECTORY_H
