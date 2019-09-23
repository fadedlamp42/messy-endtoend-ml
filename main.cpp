//PROGRAM DESCRIPTION: Driver for a messy end-to-end machine learning project
#include <iostream>
#include "Loader.hpp"
#include "Column.hpp"
#include "Table.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char**argv){
    CsvLoader loader;
    std::string fileName = (argc > 1) ? argv[1] : "";
    Table data_set = loader.read(fileName);

    data_set.print();

    return 0;
}
