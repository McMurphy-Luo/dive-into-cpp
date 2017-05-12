#include <cstring>
#include <tuple>
#include <iostream>
#include <unistd.h>
#include "cerr_log.h"
#include "socket.h"

int main(int argc, char* argv[]){
    rookie::CErrorLog log;

    rookie::Socket sk;

    sk.bind(6314);
    sk.listen();
    auto result = sk.accept();

    int fd = std::get<0>(result);

    char buf[1024];

    memset(buf, 0, sizeof(buf));
    ssize_t readed = 0;
    readed = read(fd, buf, sizeof(buf));

    log << "Connection established! fd is " << fd << std::endl;
    log << "received: " << readed << std::endl;

    while( readed != -1 && readed ){
        log << buf << std::endl;
        memset(buf, 0, sizeof(buf));
        readed = read(fd, buf, sizeof(buf));
    }

    log << "hello world!" << "\n";
    return 0;
}
