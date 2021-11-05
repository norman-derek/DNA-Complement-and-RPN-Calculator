/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 4
*/

#include "RPNCalc.h"
#include "DNAComplement.h"

int main(int argc, char** argv) //main method
{



    string mode;
    cout << "Please choose a mode. Modes are RPN or DNA. Please type one all caps." << endl;
    cin >> mode;

    if (mode == "RPN"){
        RPNCalc *rpnCalc = new RPNCalc();
        cin.ignore(); //ignore the cin here because it inteferes with the input in the prompt() method.
        rpnCalc->prompt();
        cout << "Result: " << rpnCalc->createStack() << endl;
    } else if (mode == "DNA") {
        DNAComplement *dna = new DNAComplement();
        cin.ignore(); //ignore last input because we take input again later in outputFileDNA()
        dna->outputFileDNA();
    } else {
        throw runtime_error("Invalid mode choice. Please try again!");
    }

    return 0;
}