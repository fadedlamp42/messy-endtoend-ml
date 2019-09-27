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
    data_set.setTitle("Original");

    //Table.print() method on loaded data
    data_set.print();
    
    cout << endl;

    Table t1 = data_set.dice(0.7);
    Table t2 = data_set.dice(0.7, true);
    t1.setTitle("Train");
    t2.setTitle("Test");

    t1.print();
    t2.print();


    return 0;
}
