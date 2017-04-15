#include <cstring>
#include <tuple>
#include <iostream>
#include <unistd.h>
#include "CErrorLog.h"
#include "Socket.h"

int main(int argc, char* argv[]){
    rookie::CErrorLog log;

    rookie::Socket sk;

    auto result = sk.accept();

    int fd = std::get<0>(result);

    char buf[1024];

    memset(buf, 0, sizeof(buf));
    ssize_t readed = 0;
    readed = read(fd, buf, sizeof(buf));

    log << "Connection established! fd is " << fd << rookie::CErrorLog::endl;
    log << "received: " << readed << rookie::CErrorLog::endl;

    while( readed != -1 && readed ){
        log << buf << rookie::CErrorLog::endl;
        memset(buf, 0, sizeof(buf));
        readed = read(fd, buf, sizeof(buf));
    }

    log << "hello world!" << "\n";
    return 0;
}
