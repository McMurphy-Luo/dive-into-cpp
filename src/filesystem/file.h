//
// Created by luojiayi on 4/15/17.
//

#ifndef ROOKIE_FILESYSTEM_FILE_H
#define ROOKIE_FILESYSTEM_FILE_H
#include <string>

namespace rookie{
    class File {
    public:
        static bool isRegularFile(const std::string &path);
    public:
        explicit File(std::string path):path_(std::move(path)) { };
        virtual ~File() = default;
        virtual bool exists() const;
        virtual std::string getPath() const { return path_; } ;

    protected:
        std::string path_;
    };
}



#endif //ROOKIE_FILESYSTEM_FILE_H
