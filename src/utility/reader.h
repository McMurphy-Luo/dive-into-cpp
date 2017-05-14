//
// Created by luojiayi on 5/14/17.
//

#ifndef ROOKIE_UTILITY_READER_H
#define ROOKIE_UTILITY_READER_H

#include <cstring>
#include <string>
#include <boost/optional.hpp>
#include "logstream/cerr_log.h"

namespace rookie{
    class Reader{
    public:
        Reader(int fd):
            fd_(fd),
            buf_(){};
        boost::optional<std::string> readLine();

    private:
        boost::optional<std::string> findFirstLineInBuf();
        int fd_;
        std::string buf_;
    };
}

#endif //ROOKIE_UTILITY_READER_H
