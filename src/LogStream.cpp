//
// Created by luojiayi on 17-4-5.
//
#include <cinttypes>
#include <cstring>
#include "LogStream.h"

namespace rookie{
    LogStream& LogStream::operator<<(const int32_t rhs) {
        char temp_buf[32];
        memset(temp_buf, 0, sizeof(temp_buf));
        snprintf(temp_buf, sizeof(temp_buf), "%" PRId32, rhs);
        buf_.append(temp_buf);
        return *this;
    };

    LogStream& LogStream::operator<<(const int64_t rhs){
        char temp_buf[64];
        memset(temp_buf, 0, sizeof(temp_buf));
        snprintf(temp_buf, sizeof(temp_buf), "%" PRId64, rhs);
        buf_.append(temp_buf);
        return *this;
    };

    LogStream& LogStream::operator<<(const char* rhs) {
        buf_.append(rhs);
        return *this;
    };

    LogStream& LogStream::operator<<(const std::string &rhs){
        buf_.append(rhs);
        return *this;
    }

    LogStream& LogStream::operator<<(const double rhs){
        char temp_buf[64];
        memset(temp_buf, 0, sizeof(temp_buf));
        snprintf(temp_buf, sizeof(temp_buf), "%f", rhs);
        buf_.append(temp_buf);
        return *this;
    }

    LogStream& LogStream::operator<<(const long double rhs){
        char temp_buf[128];
        memset(temp_buf, 0, sizeof(temp_buf));
        snprintf(temp_buf, sizeof(temp_buf), "%Lf", rhs);
        buf_.append(temp_buf);
        return *this;
    }
}