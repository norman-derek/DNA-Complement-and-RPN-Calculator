/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 4
*/

/* 
* This file is a template class for a stack 
* and is implemented using a doubly linked list
*/
#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
#include "doublylinkedlist.h"

using namespace std;

template <class T>
class GenStack{
    public:
        GenStack();//default constructor
        virtual ~GenStack();//destructor

        //core functions
        void push(T data);
        T pop();

        //aux/helper functions
        T peek(); //aka top()
        bool isEmpty();
        int getSize();
        void printStack();

    private:  
        DoublyLinkedList<T> *myList;
        int mSize;
        T top;
};


template <class T>
GenStack<T>::GenStack(){ //constructor
    top = -1;
    myList = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack(){ //destructor
    cout << "stack destructed" << endl;
    delete myList;
}

/*
* This is the push method, this class inserts a node to the top/front of the stack.
* push takes a single parameter of T data. T representing the data type chosen when instatiating the GenStack class and data being the data inserted to the stack
*/
template <class T>
void GenStack<T>::push(T data){ //inserts data at the top of the stack
    // dont need to check if full because linked lists are dynamic
    mSize++;
    myList->insertFront(data);
}

/*
* This is the pop method, the pop method removes the top/front node from the stack since stack are last in, first out and the last inserted node is at the top of the stack and deincrements size
* pop returns the node at the front/top of the stack 
*/
template <class T>
T GenStack<T>::pop(){ // removes and returns data at the top of the stack
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack empty can NOT pop!!");
    }
    mSize--;
    return myList->removeFront();
}

/*
* This method is called peek and is similar to pop but does not delete the top/front node but only returns the value of the top node
* This method returns temp which represents the value of the node at the top of the stack
*/
template <class T>
T GenStack<T>::peek(){ //returns the data at the top of the stack but does not remove
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack empty can NOT peek!!");
    }

    T temp = myList->removeFront();
    myList->insertFront(temp);
    return temp;

}

/*
* The isEmpty method 
* returns a boolean representing if the stack is empty
*/
template <class T>
bool GenStack<T>::isEmpty(){ //checks if stack is empty
    return (mSize == 0);
}

/*
* This method is getSize
* Returns an integer that represents the size of the stack
*/
template <class T>
int GenStack<T>::getSize(){ //returns the size of the stack
    return (mSize);
}

/*
* This method is printStack and prints a visual representation of the stack
*/
template <class T>
void GenStack<T>::printStack(){ //prints the stack
    myList->printList(true);
}

#endif