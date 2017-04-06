#include <Socket.h>

#include "CErrorLog.h"


int main(int argc, char* argv[]){
    rookie::CErrorLog log;

    log << "hello world!" << "\n";
    return 0;
}
