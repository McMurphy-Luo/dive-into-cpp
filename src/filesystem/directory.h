//
// Created by luojiayi on 4/15/17.
//

#ifndef ROOKIE_FILESYSTEM_DIRECTORY_H
#define ROOKIE_FILESYSTEM_DIRECTORY_H

#include <string>
#include <vector>
#include <memory>
#include "file.h"

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

#endif //ROOKIE_FILESYSTEM_DIRECTORY_H
