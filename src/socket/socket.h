#ifndef ROOKIE_SOCKET_SOCKET_H
#define ROOKIE_SOCKET_SOCKET_H
#include <tuple>
#include <memory>
#include <netinet/in.h>

namespace rookie{
    class Socket{
    public:
        Socket();
        void bind(uint16_t port);
        void listen();
        std::shared_ptr<int> connect(sockaddr_in server_addr);
        std::tuple<int, sockaddr_in> accept();

    private:
        std::shared_ptr<int> fd_;
    };
};


#endif //ROOKIE_SOCKET_SOCKET_H