#include "socket.h"
#include <cstring>
#include <iostream>
#include <logstream/cerr_log.h>

namespace rookie{
    Socket::Socket():
    fd_(
        std::shared_ptr<int>(
            new int(socket(AF_INET, SOCK_STREAM, 0)),
            [](int* fd){
                ::close(*fd); delete fd;
            }
        )
    )
    {
        std::cout << "Socket constructor!" << std::endl;
    };

    void Socket::bind(uint16_t port){
        in_addr this_ip_address;
        this_ip_address.s_addr = htonl(INADDR_ANY);
        sockaddr_in this_socket_param;

        memset(&this_socket_param, 0, sizeof(this_socket_param));

        this_socket_param.sin_family = AF_INET;
        this_socket_param.sin_port = htons(port);
        this_socket_param.sin_addr = this_ip_address;
        CErrorLog log;
        log << "Socket::bind call return ";
        log << ::bind(*fd_, reinterpret_cast<sockaddr *>(&this_socket_param), sizeof(this_socket_param));
        log << ".";
        log << std::endl;
        log.logCStdError();
    };

    std::shared_ptr<int> Socket::connect(sockaddr_in server_addr){
        CErrorLog log;
        int connect_result = ::connect(*fd_, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
        if (connect_result){
            log << "Socket connect return " << connect_result << std::endl;
            log.logCStdError();
        }
        return fd_;
    };

    void Socket::listen(){
        CErrorLog log;
        log << "Socket::listen call return " << ::listen(*fd_, 50) << "." << std::endl;
        log.logCStdError();
    };

    std::tuple<int, sockaddr_in> Socket::accept() {
        sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int accepted_fd = ::accept(*fd_, reinterpret_cast<sockaddr*>(&client_address), &client_address_length);
        CErrorLog log;
        log << "Socket accept returned, accept_fd is " << accepted_fd << "." << std::endl;
        log.logCStdError();

        return std::make_tuple(
            accepted_fd,
            client_address
        );
    }
}