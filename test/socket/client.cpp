//
// Created by luojiayi on 5/9/17.
//
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <boost/core/ignore_unused.hpp>
#include <boost/optional.hpp>
#include "socket/socket.h"
#include "logstream/cerr_log.h"
#include "utility/reader.h"


using boost::optional;
using rookie::Socket;
using rookie::CErrorLog;
using rookie::Reader;


int main(int argc, char *argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);


    Reader stdin_reader(STDIN_FILENO);
    Socket client_socket;
    std::shared_ptr<int> result = client_socket.connect("127.0.0.1", 6314);
    Reader socket_reader(*result);



    for (;;){
        boost::optional<std::string> line_read_from_stdin = stdin_reader.readLine();
        if (!line_read_from_stdin) break;
        ssize_t wrote = write(*result, line_read_from_stdin->c_str(), line_read_from_stdin->length());
        if (wrote < 0){
            CErrorLog log;
            log << "Write error!" << std::endl;
            log.logCStdError();
        }
    }

    return 0;
}