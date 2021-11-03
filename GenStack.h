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

template <class T>
void GenStack<T>::push(T data){ //inserts data at the top of the stack
    // dont need to check if full because linked lists are dynamic
    mSize++;
    myList->insertFront(data);
}

template <class T>
T GenStack<T>::pop(){ // removes and returns data at the top of the stack
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack empty can NOT pop!!");
    }
    mSize--;
    return myList->removeFront();
}

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


template <class T>
bool GenStack<T>::isEmpty(){ //checks if stack is empty
    return (mSize == 0);
}

template <class T>
int GenStack<T>::getSize(){ //returns the size of the stack
    return (mSize);
}

template <class T>
void GenStack<T>::printStack(){ //prints the stack
    myList->printList(true);
}

#endif