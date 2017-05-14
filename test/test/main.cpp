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

    test.erase(0, 12);

    std::string test2;
    cout << test.empty() << endl;
    cout << test.length() << endl;
    cout << test2.empty() << endl;
    cout << test2.length() << endl;
    return 0;
}