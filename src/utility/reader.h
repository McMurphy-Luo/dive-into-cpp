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
        
        boost::optional<std::string> readLine(){
            for (;;){
                boost::optional<std::string> may_be_line_already_in_buf = findFirstLineInBuf();
                if (may_be_line_already_in_buf) return may_be_line_already_in_buf;
                char buf[BUFSIZ];
                std::memset(buf, 0, BUFSIZ);
                ssize_t read_result = read(fd_, buf, BUFSIZ);
                if (read_result < 0){
                    CErrorLog log;
                    log << "read error, returned " << read_result << "." << std::endl;
                    log.logCStdError();
                    return boost::optional<std::string>();
                }
                if (read_result == 0){
                    buf_.append("\n");
                    continue;
                }
                buf_.append(buf);
            }
        };

    private:
        boost::optional<std::string> findFirstLineInBuf(){
            std::string::size_type line_feed_position = buf_.find('\n');
            if (line_feed_position != std::string::npos){
                std::string result = buf_.substr(0, line_feed_position+1);
                buf_.erase(0, line_feed_position+1);
                return result;
            }
            return boost::optional<std::string>();
        };

        int fd_;
        std::string buf_;
    };
}

#endif //ROOKIE_UTILITY_READER_H
