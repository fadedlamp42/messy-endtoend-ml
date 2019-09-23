#ifndef LOADER_H
#define LOADER_H
//Defines the Loader class. Constructor takes a string specifying
//the filetype to load, defaulting to .csv files and a boolean specifying whether to read first row as a header row
//Loader.file(std::String arg) reads a file and returns a Table object
#include <iostream>
#include <fstream>
#include "Table.hpp"
using std::cin;
using std::cout;
using std::endl;

class CsvLoader{
    private:
    bool header;
    int begin, end;

    public:
    CsvLoader(bool header_arg = true){
        header = header_arg;
        begin = 0;
        end = -1;
    }
    CsvLoader(int firstColumn, bool header_arg = true){
        header = header_arg;
        begin = (firstColumn>=0) ? firstColumn : 0;
    }
    CsvLoader(int firstColumn, int lastColumn, bool header_arg = true){
        header = header_arg;
        begin = (firstColumn>=0) ? firstColumn : 0;
        end = (lastColumn>=0) ? lastColumn : 0;
    }

    Table read(std::string name){
        Table result;
        ifstream in_file;
        in_file.open(name+".csv");

        if(!in_file){
            cout << "Bad file" << endl;
            return result;
        }

        std::string stream;
        int row = 0;
        while(std::getline(in_file, stream)){ //for every line
            std::string parse; //holds each term
            std::vector<std::string> terms; //holds all terms for line

            for(unsigned int i = 0; i<stream.size(); ++i){ //pick apart line
                char c = stream[i];
                if(c != ','){ //valid character to record
                    parse.push_back(c);

                    if(i == (stream.size()-1)){ //last character on line
                        //cout << parse << " END ";
                        terms.push_back(parse); //add final term to list
                        parse.clear(); //reset parsing helper
                        
                        if(row==0){ //first row
                            if(header){ //with header set
                                for(std::string s : terms){
                                    Column temp(s);
                                    result.columns.push_back(temp);
                                }
                            }
                            else{ //with no header set
                                for(std::string s : terms){
                                    Column temp;
                                    temp.push(s);
                                    result.columns.push_back(temp);
                                }
                            }
                        }
                        else{ //not first row
                            for(unsigned int i=0; i<terms.size(); ++i)
                                result.columns[i].push(terms[i]);
                            ++row;
                        }
                    }
                }
                else{ //end of term
                    //cout << parse << ", ";
                    terms.push_back(parse); //add non-final term to list
                    parse.clear(); //reset parsing helper
                }//end of parse logic
            }//end of per-character loop

            ++row;
        }//end of line loop

        in_file.close();
        return result;
    }//end of read function
};
#endif
