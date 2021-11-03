#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "listnode.h"

template <class T>
class DoublyLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(T d);
        void insertBack(T d);
        T removeFront();
        T removeBack();
        T removeNode(T value);
        T find(T value);
        bool isEmpty();
        unsigned int getSize();
        void printList(bool isPrintLink);
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    //empty list
    size = 0;
    front = NULL;
    back = NULL;

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //research 
    //hint: theres a loop
    ListNode<T> *curr = front;
    while( curr != 0 ) {
    ListNode<T> *next = curr->next;
    delete curr;
    curr = next;
    }
    front = 0;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    } else {
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    } else {
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("List is empty!");
    }
    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;

    } else {
        front->next->prev = NULL;
        
    }

    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;

    
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("List is empty!");
    }
    ListNode<T> *temp = back;

    if(back->prev == NULL){
        //only node in the list
        front = NULL;
    } else {
        //more than one node in the list
        back->prev->next = NULL;
    }

    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

template <class T>
T DoublyLinkedList<T>::find(T value){
    int pos = -1;

    ListNode<T> *curr = front;
    while (curr != NULL){
        ++pos;
        if(curr->data == value){
            //return pos;
            break;
        }
        curr = curr->next;
    }
    //check if curr is NULL which signifies value not in linked list
    if(curr == NULL){
        pos = -1; // or -1
    }

    return pos;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value){ //removes a specified node in the list or 
    if(isEmpty()){
        throw runtime_error("This is empty!");
    }
    //could leverage the find method
    //ListNode<T> *node = find(value); //find the node and verify it exists

    ListNode<T> *curr = front;

    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL){
            return -1;
        }
    }
    //if we make it here then we found the value
    //we found it so lets remove it

    if(curr != front && curr != back){
        //its in between two nodes
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
    }

    if(curr == front){ //its at front of the list
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){ //its at back of the list
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    T data = curr->data;
    --size;
    delete curr;
    return data;

}

template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
    if(curr == front){
        cout << "{FRONT}: ";
    }
    else if(curr == back){
        cout << "{REAR}: ";
    }
    if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
    else
        cout << "[ " << curr->data << " ] ";
    curr = curr->next;
    if(curr != 0){
        cout << " ==> ";
    }
    }
    cout << endl;
}



#endif