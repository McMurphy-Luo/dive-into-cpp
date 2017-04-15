#ifndef HELLO_SOCKET_H
#define HELLO_SOCKET_H
#include <cstdint>
#include <tuple>
#include <netinet/in.h>



namespace rookie{
    class Socket{
    public:
        Socket();
        ~Socket();
        std::tuple<int, sockaddr_in> accept();
        void close();

    private:
        void initialize();
        int fd_;
    };
};


#endif //HELLO_SOCKET_H