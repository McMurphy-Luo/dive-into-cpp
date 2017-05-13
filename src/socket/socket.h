#ifndef ROOKIE_SOCKET_SOCKET_H
#define ROOKIE_SOCKET_SOCKET_H
#include <tuple>
#include <string>
#include <memory>
#include <netinet/in.h>

namespace rookie{
    class Socket{
    public:
        Socket();
        std::shared_ptr<int> connect(const std::string &ip_address, uint16_t port_num);
        void bind(uint16_t port);
        void listen();
        std::tuple<int, sockaddr_in> accept();

    private:
        bool bound_;
        bool listened_;
        std::shared_ptr<int> fd_;
    };
};


#endif //ROOKIE_SOCKET_SOCKET_H