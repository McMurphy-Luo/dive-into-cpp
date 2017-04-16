//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_FILE_H
#define HELLO_FILE_H
#include <string>

namespace rookie{
    class File {
    public:
        explicit File(std::string path):path_(path) { };
        bool exists();
        std::string getPath() { return path_; };


    private:
        std::string path_;
    };
}



#endif //HELLO_FILE_H
