//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_DIRECTORY_H
#define HELLO_DIRECTORY_H

#include <string>
#include <vector>
#include <boost/variant.hpp>
#include <dirent.h>
#include "File.h"

namespace rookie{
    class Directory{
    public:
        explicit Directory(std::string path);
        bool exist();
        std::vector<boost::variant<File, Directory>> children();
        Directory mkdir(std::string name);
        File create(std::string name);
        void open();
        void close();
        

    private:
        std::string name_;
        DIR* handler_;
    };
}

#endif //HELLO_DIRECTORY_H
