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
    bool isDirectory(const std::string &path);
    class Directory : public File{
    public:
        explicit Directory(const std::string& path)
                :File(path){};
        bool exists() const;
        std::vector<std::shared_ptr<File>> children() const;
    };
}

#endif //ROOKIE_FILESYSTEM_DIRECTORY_H
