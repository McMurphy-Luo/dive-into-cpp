//
// Created by luojiayi on 4/15/17.
//

#ifndef HELLO_FILE_H
#define HELLO_FILE_H
#include <cstdio>
#include <string>

namespace rookie{
    class File {
    public:
        explicit File(std::string path);
        bool exists();

    private:
        FILE* file_;
    };
}



#endif //HELLO_FILE_H
