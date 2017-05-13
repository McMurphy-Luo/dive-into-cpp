#include <cstring>
#include <tuple>
#include <iostream>
#include <unistd.h>
#include <boost/core/ignore_unused.hpp>
#include "logstream/cerr_log.h"
#include "socket/socket.h"

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);

    rookie::CErrorLog log;
    rookie::Socket sk;

    sk.bind(6314);
    sk.listen();
    auto result = sk.accept();

    int fd = std::get<0>(result);

    log << "Connection established! fd is " << fd << std::endl;

    ssize_t read_bytes = 0;
    char buf[1024];
    memset(buf, 0, sizeof(buf));

    read_bytes = read(fd, buf, sizeof(buf));
    if (!(read_bytes != -1 && read_bytes)){
        log << "read error!" << std::endl;
        log.logCStdError();
    }
    log << "received: " << read_bytes << std::endl;
    log << buf << std::endl;
    return 0;
}
