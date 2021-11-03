#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class ListNode{
    public:
        ListNode();
        ListNode(T data);
        virtual ~ListNode();

        T data;
        ListNode<T> *next;
        ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode(){
    data = NULL;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
    //research this
    next = NULL; //is this all we need?
    prev = NULL;
}


#endif