//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_FILE_H
#define HELLO_FILE_H
#include <string>

namespace rookie{
    class File {
    public:
        static bool isRegularFile(const std::string &path);
    public:
        explicit File(std::string path):path_(path) { };
        virtual ~File(){};
        virtual bool exists();
        virtual std::string getPath() { return path_; };

    protected:
        std::string path_;
    };
}



#endif //HELLO_FILE_H
