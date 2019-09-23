#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "Column.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
//grouping of columns with basic accessor

class Table{
    public:
    std::vector<Column> columns;
    void push(const Column& arg){
        columns.push_back(arg);
    }

    std::string at(int x, int y){
        return columns[x].data[y];
    }

    void print(){
        if(columns.size()==0)
            return;

        size_t widths[columns.size()];

        for(unsigned int x=0; x<columns.size(); ++x)
            widths[x] = columns[x].header.size();

        for(unsigned int x=0; x<columns.size(); ++x)
            cout << columns[x].header << " ";
        cout << endl;

        for(unsigned int y=0; y<columns[0].data.size(); ++y){
            for(unsigned int x=0; x<columns.size(); ++x)
                cout << std::setw(widths[x]) << columns[x].data[y] << " ";
            cout << endl;
        }
    }
};
#endif
