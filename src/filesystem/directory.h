//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_DIRECTORY_H
#define HELLO_DIRECTORY_H

#include <string>
#include <vector>
#include <memory>
#include "File.h"

namespace rookie{
    class Directory : public File{
    public:
        static bool isDirectory(const std::string &path);

    public:
        explicit Directory(std::string path)
                :File(path){};
        bool exists() const;
        std::vector<std::shared_ptr<File>> children() const;
    };
}

#endif //HELLO_DIRECTORY_H
