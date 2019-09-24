#ifndef COLUMN_H
#define COLUMN_H
#include <vector>
//very basic container, consists of a vector of doubles and a header

struct Column{
    std::string header;
    std::vector<std::string> data;

    Column(std::string header_arg = "(no header)"){
        header = header_arg;
    }
    void push(std::string arg){
        data.push_back(arg);
    }
};
#endif
