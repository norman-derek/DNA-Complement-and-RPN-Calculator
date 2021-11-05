/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 4
*/

/*
* class called FileProcessor and takes an input file and returns a string of the first line from the txt file
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor {
    public:
        FileProcessor(); //constructor
        ~FileProcessor(); //destructor
        string processFile(); //returns the string that was read from the file
};

#endif