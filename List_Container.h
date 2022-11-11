//
// Created by paral on 2022/11/4.
//

#ifndef CPPLAB5_LIST_CONTAINER_H
#define CPPLAB5_LIST_CONTAINER_H

#include <cstddef>


class Iterator;

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
    int list_size;

public:

    list(); //constructor

    ~list(); //destructor

    list(const list<T> &x);

    void push_front(const T &x);

    void push_back(const T &x);

    void pop_front();

    void pop_back();

    unsigned size() const;

    bool empty() const;

    list<T> &operator=(const list<T> &x);

    void splice(Iterator position, list<T> &x);


    //************************declaration of the inner iterator class****************************
    class Iterator {
        friend class list<T>; //friend class of the iterator class
    private:
        Node *curr;

        Iterator(Node *ptr); //constructor with Node parameter, defined as private

    public:

        Iterator(); //default constructor

        Iterator &operator++();

        Iterator operator++(int); //post-increment of ++

        Iterator &operator--();

        Iterator operator--(int);

        T &operator*();

        bool operator==(const Iterator &x);

    };//class Iterator


    Iterator Begin();

    Iterator End();

    Iterator Insert(Iterator position, const T &x);

    void erase(Iterator position);

    void erase(Iterator first, Iterator last);

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
T &list<T>::Iterator::operator*() {
    return curr->data; //return data reference
}

template<class T>
bool list<T>::Iterator::operator==(const Iterator &x) {
    return curr == x.curr;
}


//************************implementation of the methods *************************
template<class T>
typename list<T>::Iterator list<T>::Begin() {
    return Iterator(head); //container class call the private method (constructor) of the Iterator class:
    //friend class is required
}


template<class T>
typename list<T>::Iterator list<T>::End() {
    Iterator temp = head;
    Iterator result = NULL;
    while (temp != NULL) {
        result = temp;
        temp++;
    }
    return result;
}

//Postcondition: x has been inserted in this list in front of the item that position was
//positioned at before this call. An iterator positioned at x has been returned.
template<class T>
typename list<T>::Iterator list<T>::Insert(list::Iterator position, const T &x) {
    Node *pre_Node = position.curr->pre;
    Node *new_Node = new Node;
    new_Node->data = x;

    pre_Node->next = new_Node;
    new_Node->pre = pre_Node;
    new_Node->next = position.curr;
    position.curr->pre = new_Node;
    list_size++;

    Iterator new_position = Iterator(new_Node);
    return new_position;
}


//************************implementation of the linked list class template**************************
template<class T>
list<T>::list() {
    head = NULL; //empty list
    tail = NULL;
    list_size = 0;
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

//Postcondition: this list has been constructed and initialized to a copy of x
template<class T>
list<T>::list(const list<T> &x) {
    this->head = NULL;
    this->tail = NULL;
    this->list_size = 0;

    Iterator itr_prev(x.head);
    while (itr_prev.curr->next != NULL) {
        push_back(itr_prev.curr->data);
        itr_prev++;
    }
    push_back(itr_prev.curr->data);
}


template<class T>
void list<T>::push_front(const T &x) {
    Node *newHead = new Node;
    newHead->data = x;
    newHead->next = head;
    newHead->pre = NULL;
    if (tail == NULL) {   //execute only if the list is newly created
        tail = newHead;
    }
    if (head != NULL) {
        head->pre = newHead;
    }
    head = newHead;
    list_size++;
}

template<class T>
void list<T>::push_back(const T &x) {
    if (head == NULL) {
        push_front(x);
        return;
    }
    Node *newTail = new Node;
    newTail->data = x;
    newTail->next = NULL;
    newTail->pre = tail;
    tail->next = newTail;
    tail = newTail;
    list_size++;
}

template<class T>
void list<T>::pop_front() {
    if (this->list_size != 0) {
        head = head->next;
        head->pre = NULL;
        list_size--;
    } else{
        std::cout << "The list is empty now!" << std::endl;
    }
}

template<class T>
void list<T>::pop_back() {

}

template<class T>
unsigned list<T>::size() const {
    return list_size;
}

template<class T>
bool list<T>::empty() const {
    return list_size == 0;
}


#endif

