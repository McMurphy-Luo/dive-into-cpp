//
// Created by luojiayi on 17-4-4.
//

#ifndef HELLO_LOGSTREAM_H
#define HELLO_LOGSTREAM_H
#include <cstdint>
#include <string>
#include <boost/noncopyable.hpp>

namespace rookie{
    class LogStream: boost::noncopyable{
    public:
        LogStream():buf_(){};
        virtual ~LogStream(){};
        LogStream& operator<<(const int32_t rhs);
        LogStream& operator<<(const int64_t rhs);
        LogStream& operator<<(const std::string &rhs);
        LogStream& operator<<(const char* rhs);
        LogStream& operator<<(const double rhs);
        LogStream& operator<<(const long double rsh);

    protected:
        std::string buf_;
    };
}


#endif //HELLO_LOGSTREAM_H
