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
        enum pos{begin, middle, end, random}; //implement random split
    std::vector<Column> columns;
    void push(const Column& arg){
        columns.push_back(arg);
    }

    std::string at(int x, int y){
        return columns[x].data[y];
    }

    Table slice(int from, int to = 0){
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

    /*arguments:
     * proportion: from 0-1, % of values to return
     * position: [begin...], [..middle..], or [...end] (might replace)
     * complement: boolean which when true, exactly inverts values returned*/
    Table dice(double proportion, pos position = pos::begin, bool complement = false){
        int new_size = abs(int(columns.back().data.size()*proportion));
        int column_size = columns.back().data.size();
        cout << proportion*100 << "\% of " << columns.back().data.size() << ": " << new_size << endl;

        Table result;
        bool keep[column_size];
        for(int x=0; x<column_size; ++x)
            keep[x] = false;

        //write expression to express beginning and end
        switch(position){
            case pos::begin: //keep "size" values from beginning
                for(int x=0; x<new_size; ++x)
                    keep[x] = true;
                break;
            case pos::middle:
                for(int x=0; x<new_size; ++x)
                    keep[x+(column_size/3)] = true;
                break;
            case pos::end: //keep "size" values from end
                for(int x=column_size-1; 
                        x>column_size-new_size-1; --x)
                    keep[x] = true;
                break;
            case pos::random:
                //IMPLEMENT RANDOM SELECTION OF ELEMENTS
                break;
        }

        for(Column i : columns){ //for each column in original table
            Column temp(i.header); //make a new column with the same header
            for(int x=0; x<column_size; ++x){//for every "keep" value
                bool b = keep[x];
                if(complement)
                    b = !b;

                if(b) //if keeping index
                    temp.data.push_back(i.data[x]); //push from original table to new
            }
            result.push(temp);
        }

        return result;


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
