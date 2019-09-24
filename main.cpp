//PROGRAM DESCRIPTION: Driver for a messy end-to-end machine learning project
#include <iostream>
#include "core/Loader.hpp"
#include "core/Column.hpp"
#include "core/Table.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char**argv){
    //declare a loader object
    CsvLoader loader;

    //parse filename argument
    std::string fileName = (argc > 1) ? argv[1] : "";

    //load filename.csv into data_set Table object
    Table data_set = loader.read(fileName);

    //Table.print() method on loaded data
    data_set.print();

    data_set.dice(0.3, Table::middle);


    return 0;
}
