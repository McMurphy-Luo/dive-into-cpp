//
// Created by luojiayi on 4/15/17.
//

#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <boost/core/ignore_unused.hpp>
#include <filesystem/Directory.h>

void iter_directory(const rookie::Directory &d, int depth){
    char buf[BUFSIZ];
    memset(buf, '-', BUFSIZ);
    buf[BUFSIZ - 1] = '\0';
    if (depth * 4 < BUFSIZ){
        buf[depth * 4] = '\0';
    }
    std::cout << buf << d.getPath() << std::endl;

//    if (depth > 2){
//        std::cout << buf << ".................." << std::endl;
//        return;
//    }

    for (auto child : d.children()){
        if (rookie::File::isRegularFile(child->getPath())){
            std::cout << buf << "----" << child->getPath() << std::endl;
            continue;
        }
        if (rookie::Directory::isDirectory(child->getPath())){
            iter_directory(*(std::dynamic_pointer_cast<rookie::Directory>(child)), depth+1);
        }
    }
}

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);
    std::cout << "hello world!" << std::endl;
    rookie::Directory directory("/home/luojiayi/projects/hello");

    iter_directory(directory, 0);

    return 0;
}