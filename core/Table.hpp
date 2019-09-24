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

    Table trim(int from, int to = 0){
        int lower = 0, upper = columns.size()-1;

        //bound checking for indices
        //could be implemented with conditionals but this is legible
            //checking starting index
        if(from < lower)
            from = 0;
        if(from>upper)
            from = upper;
            //checking ending index
        if (to < from)
            to = from;
        if(to>upper)
            to = upper;

        //print range split for debugging
        //cout << "[" << from << ", " << to << "]" << endl; //debug

        //declare and define output table
        Table result;
        for(int x=from; x<=to; ++x)
            result.push(columns[x]);

        return result;
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
