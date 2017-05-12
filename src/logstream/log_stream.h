//
// Created by luojiayi on 17-4-4.
//

#ifndef ROOKIE_LOGSTREAM_LOG_STREAM_H
#define ROOKIE_LOGSTREAM_LOG_STREAM_H
#include <cstdint>
#include <string>
#include <iostream>
#include <boost/noncopyable.hpp>

namespace rookie{
    class LogStream: public boost::noncopyable{
    public:
        LogStream():buf_(){};
        virtual ~LogStream() = default;
        LogStream& operator<<(const int32_t rhs);
        LogStream& operator<<(const int64_t rhs);
        LogStream& operator<<(const std::string &rhs);
        LogStream& operator<<(const char* rhs);
        LogStream& operator<<(const double rhs);
        LogStream& operator<<(const long double rsh);
        LogStream& operator<<(const char rhs);
        LogStream& operator<<(std::ostream& (*endl)(std::ostream&));

    protected:
        std::string buf_;
    };
}




#endif //ROOKIE_LOGSTREAM_LOG_STREAM_H
