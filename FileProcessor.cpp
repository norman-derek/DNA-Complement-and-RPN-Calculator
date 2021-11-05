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

#include "FileProcessor.h"

FileProcessor::FileProcessor() { //constructor

}

FileProcessor::~FileProcessor() { //destructor

}

/*
* This class if file processor, it process a text file given the file path and returns the first line of the text file as a string
* returns a string representing the first line of the file
*/
string FileProcessor::processFile(){ 
    cout << "Please provide file path" << endl;
    string filePath;
    cin >> filePath;
    if(filePath.length() < 4) { //checks if file name length is 3 or less which is not possible with .txt extension
        cout << "please use a valid file name with .txt" << endl;
        processFile(); //recalls function so user can input correct file
    }
    else if(filePath.substr(filePath.length() - 4) != ".txt"){ //check if file has .txt extension
        cout << "please input a .txt file for the input" << endl;

        processFile();
    }
    
    string line;
    ifstream input(filePath); //opens input fule for reading
    
    if(input.is_open()){ //while input file is open 
        getline(input, line); //gets the DNA sequence
    }

    input.close();
    return line;
}