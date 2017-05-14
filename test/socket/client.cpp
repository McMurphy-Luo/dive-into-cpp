//
// Created by luojiayi on 5/9/17.
//
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <boost/core/ignore_unused.hpp>
#include <boost/optional.hpp>
#include <socket/socket.h>
#include <logstream/cerr_log.h>

using rookie::Socket;
using rookie::CErrorLog;
using boost::optional;



int main(int argc, char *argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);


    Reader reader(STDIN_FILENO);

    std::cout << reader.readLine() << std::endl;

    Socket client_socket;
    std::shared_ptr<int> result = client_socket.connect("127.0.0.1", 6314);
    char message[] = "Hello World!";
    ssize_t wrote = write(*result, message, sizeof(message));
    if (wrote < 0){
        CErrorLog log;
        log << "Write error!" << std::endl;
        log.logCStdError();
    }
    if (wrote < static_cast<ssize_t>(sizeof(message))){
        CErrorLog log;
        log << "Write bytes less than that should be wrote! Already wrote " << wrote << ".";
        log.logCStdError();
    }
    sleep(5);
    return 0;
}