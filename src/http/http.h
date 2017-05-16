//
// Created by luojiayi on 5/15/17.
//

#ifndef ROOKIE_HTTP_HTTP_H
#define ROOKIE_HTTP_HTTP_H

#include <string>
#include <vector>

namespace rookie{
    class HTTP{
    protected:
        std::vector<std::string> header_;
        std::string body_;
    };
}

#endif //ROOKIE_HTTP_HTTP_H
