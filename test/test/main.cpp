//
// Created by luojiayi on 5/14/17.
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <boost/core/ignore_unused.hpp>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
    boost::ignore_unused(argc);
    boost::ignore_unused(argv);
    std::string test = "Hello World!";

    cout << test.find("o") << endl;
    cout << test.find("k") << endl;
    cout << test.substr(0, 7) << endl;
    return 0;
}