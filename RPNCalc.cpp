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

#include "RPNCalc.h"

RPNCalc::RPNCalc(){ //constructor
    mPostfixString = "";
    stack = new GenStack<string>();
}

RPNCalc::~RPNCalc(){ //destructor
    delete stack;
}

/*
* this method is prompt, it prompts the user for an equation in postfix notation and assigns it to the string mPostfixString
*/
void RPNCalc::prompt(){ //prompts for Postfix Notation and assigns it to a string to be used in other methods
    cout << "Please enter the postfix notation for the problem you want solved with spaces in between operands and operators." << endl;
    getline(cin, mPostfixString); //assigns input to mPostfixString
}

/*
* This method is createStack, createStack creates a stack of integers from the mPostfixString string and performs the operation when it detects an operator
* returns total representing the total when all math operations are completed
* Stack only has 2 nodes at a time because most operations are between two numbers
*/
int RPNCalc::createStack(){
    int total;
    string data = "";
    for(int i = 0; i < mPostfixString.length(); ++i){ 
        if (i == mPostfixString.length() - 1) { //since there is no whitespace after the last data this accounts for the last data in the sentence
            data += mPostfixString[i]; //adds the last character of the string to the data  
        } else if (!isspace(mPostfixString[i])){ // while there is no whitespace it will add the characters of the data to a string called data
            data += mPostfixString[i];
        } else if (isspace(mPostfixString[i])){ //once there is a whitespace it translates the english word to tutnese and adds it to the tutnese sentence
            if(!isInteger(data)){
                total = calculate(data); //calculates total of most recent operator
                stack->push(to_string(total)); //pushes total of last operation to stack for next operation
            }
            else {
            stack->push(data); //pushed number to the stack
            }
        data = ""; // resets data to being empty for the next data in the sentence
        } 
    }

    
    if(!isInteger(data)){
        total = calculate(data);
    }
    else {
        stack->push(data); //pushes the last remaining piece of data to the stack
        total = calculate(data);
        stack->printStack();
    }

    stack->printStack();
    if(stack->getSize() >= 1){ //last check to see if the equation is valid or not
        throw runtime_error("CANNOT EVALUATE. INVALID EQUATION"); //throws error for invalid equation
    }

    return total;
}

/*
* This method is calculate, this method takes the operator and decides which type of math to perform and returns the total after it performs the math
* returns total representing the total of the single math operation that was completed
*/
int RPNCalc::calculate(string op){ //given the operator it preforms the operation corresponding to the operator to the two numbers in the stack
    int total;
        if (isAddition(op)){
            total = addition(); // assigns the result of addition to total
        }
        else if (isSubtraction(op)){
            total = subtraction(); //assigns the result of subtraction to total
        }
        else if (isMultiplication(op)){
            total = multiplication(); //assigns the result of multiplication to total
        }
        else if (isDivision(op)){
            total = division(); //assigns the result of division to total
        }
        else if (isModulo(op)){
            total = modulo(); //assigns the result of modulo to total
        }
        else{
            throw runtime_error("incorrect operators. Please try again");
        }
    
    return total; //returns the total from whatever operation was completed
}

/*
* This method is addition, adds two ints together from the stack
* returns sum representing the sum of the addition
*/
int RPNCalc::addition(){ //addition a b + = (a + b)
    int sum = 0;

    //since we push to the stack in the order of the postfix a will be at the bottom and b will be above it in the 2nd position
    int b = stoi(stack->pop()); //first pop is b because it is at the 2nd position of stack
    int a = stoi(stack->pop()); //second pop is a because that is the bottom of the stack 
    sum = a + b;

    return sum;
}

/*
* This method is subtraction, performs subtraction on two integers from the stack
* returns difference representing subtraction of two numbers
*/
int RPNCalc::subtraction(){ //subtraction, a b - = (a-b)
    int difference;

    //since we push to the stack in the order of the postfix a will be at the bottom and b will be above it in the 2nd position
    int b = stoi(stack->pop()); //first pop is b because it is at the 2nd position of stack
    int a = stoi(stack->pop()); //second pop is a because that is the bottom of the stack
    difference = a - b; //assigns result of subtraction to difference

    return difference;
}

/*
* This method is multiplication, multiplies two numbers from the stack together
* returns product representing the product of two integers that have been multiplied together
*/
int RPNCalc::multiplication(){ //multiplication, a b * = (a * b)
    int product;

    //since we push to the stack in the order of the postfix a will be at the bottom and b will be above it in the 2nd position
    int b = stoi(stack->pop()); //first pop is b because it is at the 2nd position of stack
    int a = stoi(stack->pop()); //second pop is a because that is the bottom of the stack
    product = a * b; //assings result of (a * b) to product
    
    return product;
}

/*
* This method is division, divides two integers from the stack
* returns quotient representing the result of the two divided integers
*/
int RPNCalc::division(){ //division, a b / = (a / b)
    int quotient;

    //since we push to the stack in the order of the postfix a will be at the bottom and b will be above it in the 2nd position
    int b = stoi(stack->pop()); //first pop is b because it is at the 2nd position of stack
    int a = stoi(stack->pop()); //second pop is a because that is the bottom of the stack
    quotient = a / b; //assings result of (a / b)

    return quotient;
}

/*
* This method is modulo, performs modulo on two integers from the stack
* returns result representing the result of the modulo performed on the integers
*/
int RPNCalc::modulo(){ //modulo, a b % = (a % b)
    int result;

    //since we push to the stack in the order of the postfix a will be at the bottom and b will be above it in the 2nd position
    int b = stoi(stack->pop()); //first pop is b because it is at the 2nd position of stack
    int a = stoi(stack->pop()); //second pop is a because that is the bottom of the stack
    result = a % b; //assigns result of (a % b) to result

    return result;
}

/*
* This method is isAddition, returns if an operator is addition
* returns true or false representing if the operator is addition or not
*/
bool RPNCalc::isAddition(string op){ //checks if the operator is addition
    return (op == "+");
}

/*
* This method is isMultiplication, returns if an operator is multiplication
* returns true or false representing if the operator is multiplication or not
*/
bool RPNCalc::isMultiplication(string op){ //checks if the operator is multiplication
    return (op == "*");
}

/*
* This method is isSubtraction, returns if an operator is subtraction
* returns true or false representing if the operator is subtraction or not
*/
bool RPNCalc::isSubtraction(string op){ //checks if the operator is subtraction
    return (op == "-");
}

/*
* This method is isDivision, returns if an operator is division
* returns true or false representing if the operator is division or not
*/
bool RPNCalc::isDivision(string op){ //checks if the operator is division
    return (op == "/");
}

/*
* This method is isModulo, returns if an operator is modulo
* returns true or false representing if the operator is modulo or not
*/
bool RPNCalc::isModulo(string op){ //checks if the operator is modulo
    return (op == "%");
}

/*
* This method is isInteger, takes a string and returns if the string is an integer or not
* returns true or false representing if the string is an integer or not
*/
bool RPNCalc::isInteger(string s){
    string num = s;
    for(int i = 0; i < num.size(); ++i){
        if(!isdigit(num[i])){
            return false;
        }
    }

    return true;
}

