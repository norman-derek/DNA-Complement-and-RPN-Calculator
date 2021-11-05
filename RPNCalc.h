/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 4
*/

/*
* This is the RPNCalc class. This class is a simple representation of a calculator that uses postFix notation.
*/

#ifndef RPNCALC_H
#define RPNCALC_H

#include "GenStack.h"


class RPNCalc {
    public:
        RPNCalc(); //constructor
        ~RPNCalc(); //destructor 
        void prompt(); //prompts for postfix notation
        int createStack(); //creates a stack of chars from the input string
        int calculate(string op); //calculates the postfix notation
        int addition(); //adds two numbers together
        int subtraction(); //subtracts
        int multiplication(); //multiplies two numbers together and also checks for addition within 
        int division();
        int modulo();
        bool isAddition(string s); //checks if the top of the stack is addition
        bool isMultiplication(string s); //checks if the top of the stack is multiplication
        bool isSubtraction(string s); //checks if the top of the stack is subtraction
        bool isDivision(string s); //checks if the top of the stack is division
        bool isModulo(string s); //checks if the top of the stack is modulo
        bool isInteger(string s); //checks if a string is a integer

    private:
        string mPostfixString;
        GenStack<string> *stack;

};

#endif