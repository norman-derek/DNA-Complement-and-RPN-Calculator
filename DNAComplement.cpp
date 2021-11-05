/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 4
*/

/*
* class called DNAComplement that reads a DNA sequence from a text file, calculates the complement of the DNA sequence,
* and calculates the reverse complement of the DNA sequence
*/

#include "DNAComplement.h"


DNAComplement::DNAComplement(){ //constructor
    mDNASequence = "";
    stack = new GenStack<char>();
}

DNAComplement::~DNAComplement(){ //destructor
    delete stack;
}

/*
* This method is outputFile, it outputs a txt file containing the original sequence, complement, and reverse complement.
*/
void DNAComplement::outputFileDNA(){

    FileProcessor *f = new FileProcessor();
    mDNASequence = f->processFile(); //process the file and assigns the text from the file to mDNASequence

    ofstream dnaOutput("dnaoutput.txt");

    cout << endl; //to make output a little neater
    dnaOutput << "Sequence: " << mDNASequence << endl; //writes the dna sequence to output file
    cout << "Sequence: " << mDNASequence << endl; //prints the dna sequence to the console
    dnaOutput << "Complement: " << complement() << endl; //writes the dna sequence complement to output file
    cout << "Complement: " << complement() << endl; //prints the complement to the console
    dnaOutput << "Reverse Complement: " << reverseComplement() << endl; //writes the dna sequence reverse complement to output file
    cout << "Reverse Complement: " << reverseComplement() << endl; //prints reverse complement to the console
    cout << endl; //to make output a little neater

    dnaOutput.close();
    delete f;
}

/*
* This method is complement, it calculates the complement of the DNA sequence
* returns a string complement representing the complement of the DNA sequence
*/
string DNAComplement::complement(){
    string complement = "";

    for (int i = 0; i < mDNASequence.length(); ++i){
        if(mDNASequence[i] == 'A'){ //if the char is A
            complement += 'T'; //complement of A is T
        }
        else if (mDNASequence[i] == 'T'){ //if the char is T
            complement += 'A'; //Complement of T is A
        }
        else if (mDNASequence[i] == 'G'){ //if the char is G
            complement += 'C'; //complement of G is C
        }
        else if (mDNASequence[i] == 'C'){ //if the char is C
            complement += 'G'; //complement of C is G
        } else {
            throw runtime_error("NOT A VALID DNA SEQUENCE");
        }
    }

    return complement;
    }


/*
* This method is reverseComplement, it calculates the reverse complement of the DNA sequence 
* returns a string reverseComplement representing the reverse complement of the DNA sequence
*/
string DNAComplement::reverseComplement(){
    string tempComplement = complement();
    string reverseComplement = "";

    for(int i = 0; i < tempComplement.length(); ++i){ //pushes each character in the complement string to the stack
        stack->push(tempComplement[i]); 
    }
    
    while (!stack->isEmpty()){ //since stacks are last in first out we can just pop each char from the stack and add it to the reverseComplement string and it will be reversed
        reverseComplement += stack->pop();
    }
    
    
    return reverseComplement;
}
