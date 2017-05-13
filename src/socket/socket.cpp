#include "socket.h"
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include "logstream/cerr_log.h"

namespace rookie{
    Socket::Socket():
    bound_(false),
    listened_(false),
    fd_(std::shared_ptr<int>(
        new int(socket(AF_INET, SOCK_STREAM, 0)),
        [](int* fd){
            ::close(*fd);
            delete fd;
        }
    )){};

    std::shared_ptr<int> Socket::connect(const std::string &ip_address, uint16_t port_num){
        sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        inet_pton(AF_INET, ip_address.c_str(), &server_address.sin_addr);
        server_address.sin_port = htons(port_num);
        int connect_result = ::connect(*fd_, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address));
        if (connect_result){
            CErrorLog log;
            log << "Socket connect error, returned " << connect_result << "." << std::endl;
            log.logCStdError();
        }
        return fd_;
    };

    void Socket::bind(uint16_t port){
        if (bound_) return;
        in_addr this_ip_address;
        this_ip_address.s_addr = htonl(INADDR_ANY);
        sockaddr_in this_socket_param;
        memset(&this_socket_param, 0, sizeof(this_socket_param));
        this_socket_param.sin_family = AF_INET;
        this_socket_param.sin_port = htons(port);
        this_socket_param.sin_addr = this_ip_address;
        int bind_result = ::bind(*fd_, reinterpret_cast<sockaddr *>(&this_socket_param), sizeof(this_socket_param));
        if (bind_result){
            CErrorLog log;
            log << "Socket::bind call error, returned " << bind_result << "." << std::endl;
            log.logCStdError();
            return;
        }
        bound_ = true;
    };

    void Socket::listen(){
        if (listened_) return;
        int listen_result = ::listen(*fd_, 50);
        if (listen_result){
            CErrorLog log;
            log << "Socket::listen call return " << listen_result << "." << std::endl;
            log.logCStdError();
        }
        listened_ = true;
    };

    std::tuple<int, sockaddr_in> Socket::accept() {
        sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int accepted_fd = ::accept(*fd_, reinterpret_cast<sockaddr*>(&client_address), &client_address_length);
        if (accepted_fd == -1){
            CErrorLog log;
            log << "Socket::accept error returned, accept_fd is " << accepted_fd << "." << std::endl;
            log.logCStdError();
        }

        return std::make_tuple(
            accepted_fd,
            client_address
        );
    }
}