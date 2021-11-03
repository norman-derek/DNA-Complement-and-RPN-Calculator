#ifndef RPNCALC_H
#define RPNCALC_H

#include "GenStack.h"
#include <sstream>

class RPNCalc {
    public:
        RPNCalc();
        ~RPNCalc();
        void prompt(); //prompts for postfix notation
        void createStack();
        void calculate(); //calculates the postfix notation
        int addition(); //adds two numbers together

    private:
        string mPostfixString;
        GenStack<char> *stack;

};

#endif