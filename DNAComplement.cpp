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
* This method is processFile, it reads a text file with a DNA sequence and outputs a txt file containing the original sequence, complement, and reverse complement.
*/
void DNAComplement::processFile(){
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
    
    ofstream dnaOutput("dnaoutput.txt"); //opens file for writing
    ifstream dnaInput(filePath); //opens input fule for reading

    if(dnaInput.is_open()){ //while input file is open 
        getline(dnaInput, mDNASequence); //gets the DNA sequence
    }

    cout << endl; //to make output a little neater
    dnaOutput << "Sequence: " << mDNASequence << endl; //writes the dna sequence to output file
    cout << "Sequence: " << mDNASequence << endl; //prints the dna sequence to the console
    dnaOutput << "Complement: " << complement() << endl; //writes the dna sequence complement to output file
    cout << "Complement: " << complement() << endl; //prints the complement to the console
    dnaOutput << "Reverse Complement: " << reverseComplement() << endl; //writes the dna sequence reverse complement to output file
    cout << "Reverse Complement: " << reverseComplement() << endl; //prints reverse complement to the console
    cout << endl; //to make output a little neater

    dnaInput.close();
    dnaOutput.close();
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
