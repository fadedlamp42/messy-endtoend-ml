//PROGRAM DESCRIPTION: Driver for a messy end-to-end machine learning project
#include <iostream>
#include "Loader.hpp"
#include "Column.hpp"
#include "Table.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char**argv){
    CsvLoader l1;
    Table t1 = l1.read("data/test");
    /*Column c1("dude nice");

    for(int x=0; x<10; ++x)
        c1.push(x);

    for(int x=0; x<5; ++x)
        t1.push(c1);*/

    t1.print();

    return 0;
}
