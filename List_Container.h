//
// Created by paral on 2022/11/4.
//

#ifndef CPPLAB5_LIST_CONTAINER_H
#define CPPLAB5_LIST_CONTAINER_H

#include <cstddef>

template<class T>
class list {
private:
    struct Node {
        T data;
        Node *next;
        Node *pre;
    };

    Node *head;
    Node *tail;
    int size;

public:

    list(); //constructor

    ~list(); //destructor

    int getLength() const; //get the number of elements

    bool isEmpty() const; //check whether the container is empty

    void push_front(const T &x);

    void push_back(const T &x);

    //************************declaration of the inner iterator class****************************
    class Iterator {
        friend class list<T>; //friend class of the iterator class
    private:
        Node *curr;

        Iterator(Node *ptr); //constructor with Node parameter, defined as private

    public:

        Iterator(); //default constructor

        Iterator operator++(int); //post-increment of ++

        Iterator operator--(int);

        T &operator*() const;

        bool operator==(Iterator other) const;

    };//class Iterator


    Iterator Begin() const;

    Iterator End() const;

    Iterator Tail();

};


//************************Implementation of the iterator inner class**************************
template<class T>
list<T>::Iterator::Iterator() {
    curr = NULL;
}

template<class T>
list<T>::Iterator::Iterator(Node *ptr) {
    curr = ptr;
}

template<class T>
typename list<T>::Iterator list<T>::Iterator::operator++(int) {
    Iterator temp = *this; //default copy constructor
    this->curr = curr->next;
    return temp; //return iterator object
}


template<class T>
typename list<T>::Iterator list<T>::Iterator::operator--(int) {
    Iterator temp = *this; //default copy constructor
    this->curr = curr->pre;
    return temp; //return iterator object
}

template<class T>
T &list<T>::Iterator::operator*() const {
    return curr->data; //return data reference
}

template<class T>
bool list<T>::Iterator::operator==(const Iterator other) const {
    return curr == other.curr;
}


//************************implementation of the Begin and End position**************************
template<class T>
typename list<T>::Iterator list<T>::Begin() const {
    return Iterator(head); //container class call the private method (constructor) of the Iterator class:
    //friend class is required
}

template<class T>
typename list<T>::Iterator list<T>::End() const {
    return Iterator(); //NULL pointer
}

template<class T>
typename list<T>::Iterator list<T>::Tail() {
    Iterator temp = head;
    Iterator result = NULL;
    while (temp != NULL) {
        result = temp;
        temp++;
    }
    return result;
}


//************************implementation of the linked list class template**************************
template<class T>
list<T>::list() {
    head = NULL; //empty list
    tail = NULL;
    size = 0;
}

template<class T>
list<T>::~list() {
    Node *current = head;
    Node *temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp; //release
    }
}

template<class T>
void list<T>::push_front(const T &x) {
    Node *newHead = new Node;
    newHead->data = x;
    newHead->next = head;
    if (tail == NULL) {   //execute only if the list is newly created
        tail = head;
    }
    if (head != NULL) {
        head->pre = newHead;
    }
    head = newHead;
    size++;
}

template<class T>
void list<T>::push_back(const T &x) {
    if (head == NULL){
        push_front(x);
    }
    Node* newTail = new Node;
    newTail->data = x;
    newTail->next = NULL;
    newTail->pre = tail;
    tail->next = newTail;
    tail = newTail;
    size++;
}

template<class T>
int list<T>::getLength() const {
    return size;
}


template<class T>
bool list<T>::isEmpty() const {
    return size == 0;
}


#endif

