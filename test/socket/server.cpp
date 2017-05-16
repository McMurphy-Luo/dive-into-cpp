#include <cstring>
#include <tuple>
#include <iostream>
#include <unistd.h>
#include <boost/core/ignore_unused.hpp>
#include <boost/optional.hpp>
#include "logstream/cerr_log.h"
#include "socket/socket.h"
#include "utility/reader.h"

using rookie::CErrorLog;
using rookie::Socket;
using rookie::Reader;

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);

    Socket sk;
    sk.bind(6314);
    sk.listen();
    auto result = sk.accept();
    int fd = std::get<0>(result);
    std::cout << "Connection established! fd is " << fd << "." << std::endl;

    Reader client_reader(fd);

    for( ; ; ){
        boost::optional<std::string> line_read = client_reader.readLine();
        if (!line_read) break;
        std::cout << line_read.value();
    }
    return 0;
}
