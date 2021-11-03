#include "RPNCalc.h"

RPNCalc::RPNCalc(){
    mPostfixString = "";
    stack = new GenStack<char>();
}

RPNCalc::~RPNCalc(){
    delete stack;
}

void RPNCalc::prompt(){ //prompts for Postfix Notation and assigns it to a string to be used in other methods
    cout << "Please enter the postfix notation for the problem you want solved." << endl;
    cin >> mPostfixString;
}

void RPNCalc::createStack(){

    for (int i = 0; i < mPostfixString.size(); ++i){
        //int d = mPostfixString[i] - '0'; //converts ascii character from string to the integer representation
        stack->push(mPostfixString[i]);
    }

    //stack->printStack();
}

void RPNCalc::calculate(){
    for(int i = 0; i < mPostfixString.size(); ++i){
        if(stack->pop() == '+'){
            stack->pop();
            addition();
        }
    }
}

int RPNCalc::addition(){
    int sum = 0;
    while

    cout << sum << endl;
    return sum;
}