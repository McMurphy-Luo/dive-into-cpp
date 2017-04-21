#include "socket.h"
#include <cstring>
#include <iostream>
#include <functional>
#include <logstream/cerr_log.h>

namespace rookie{
    Socket::Socket():
    fd_(socket(AF_INET, SOCK_STREAM, 0)){
        std::cout << "Socket constructor!" << std::endl;
        initialize();
    };

    Socket::~Socket(){
        close();
    }

    void Socket::initialize() {
        in_addr this_ip_address;
        this_ip_address.s_addr = htonl(INADDR_ANY);
        sockaddr_in this_socket_param;

        memset(&this_socket_param, 0, sizeof(this_socket_param));

        this_socket_param.sin_family = AF_INET;
        this_socket_param.sin_port = htons(6314);
        this_socket_param.sin_addr = this_ip_address;
        CErrorLog log;
        log << "Socket::initialize bind call return ";
        log << bind(fd_, reinterpret_cast<sockaddr *>(&this_socket_param), sizeof(this_socket_param));
        log << CErrorLog::endl;
        log.logCStdError();

        log << "Socket::initialize listen call return ";
        log << listen(fd_, 50);
        log << CErrorLog::endl;
        log.logCStdError();
    };

    std::tuple<int, sockaddr_in> Socket::accept() {
        sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int accepted_fd = ::accept(fd_, reinterpret_cast<sockaddr*>(&client_address), &client_address_length);
        CErrorLog log;
        log << "Socket accept returned, accept_fd is " << accepted_fd << ";" << CErrorLog::endl;
        log.logCStdError();

        return std::make_tuple(
            accepted_fd,
            client_address
        );
    }

    void Socket::close(){

    }
}