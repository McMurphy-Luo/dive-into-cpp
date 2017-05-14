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

class Reader{
public:
    Reader(int fd):
        fd_(fd),
        buf_()
    {};
    std::string readLine(){
        optional<std::string> may_be_line_already_in_buf = findFirstLineInBuf();
        if (may_be_line_already_in_buf){
            return may_be_line_already_in_buf.get();
        }
        char buf[BUFSIZ];
        memset(buf, 0, BUFSIZ);
        read(fd_, buf, BUFSIZ);
        buf_.append(buf);
        optional<std::string> first_line = findFirstLineInBuf();
        return first_line.get();
    };

private:
    optional<std::string> findFirstLineInBuf(){
        std::string::size_type line_feed_position = buf_.find('\n');
        if (line_feed_position != std::string::npos){
            std::string result = buf_.substr(0, line_feed_position+1);
            buf_.erase(0, line_feed_position+1);
            return result;
        }
        return optional<std::string>();
    };

    int fd_;
    std::string buf_;
};

int main(int argc, char *argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);


    struct Reader reader(STDIN_FILENO);

    std::cout << reader.readLine() << std::endl;

//    Socket client_socket;
//    std::shared_ptr<int> result = client_socket.connect("127.0.0.1", 6314);
//    char message[] = "Hello World!";
//    ssize_t wrote = write(*result, message, sizeof(message));
//    if (wrote < 0){
//        CErrorLog log;
//        log << "Write error!" << std::endl;
//        log.logCStdError();
//    }
//    if (wrote < static_cast<ssize_t>(sizeof(message))){
//        CErrorLog log;
//        log << "Write bytes less than that should be wrote! Already wrote " << wrote << ".";
//        log.logCStdError();
//    }
//    sleep(5);
//    return 0;
}