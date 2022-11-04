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
    int size;

public:

    list(); //constructor

    ~list(); //destructor

    int getLength() const; //get the number of elements

    bool isEmpty() const; //check whether the container is empty

    // Postcondition: A node with newData has been inserted at the
    //                head of the Linked container.
    void addHead(const T &newData);

    //************************declaration of the inner iterator class****************************
    class Iterator {
        friend class list<T>; //friend class of the iterator class
    private:
        Node *curr;

        // Postcondition: The iterator has been constructed from ptr.
        Iterator(Node *ptr); //constructor with Node parameter, defined as private

    public:

        // Postcondition: The iterator has been constructed.
        Iterator(); //default constructor

        // Precondition: The iterator is positioned at an item.
        // Postcondition: The iterator has been positioned at
        // the next item in the Linked object.
        Iterator operator++(int); //post-increment of ++

        Iterator operator--(int);
        /******Reload of --********/

        // Postcondition: A reference to the item the iterator
        // is positioned at has been returned.
        T &operator*() const;

        // Postcondition: true has been returned if the
        // iterator is equal to other; otherwise,
        // false has been returned.
        bool operator==(const Iterator other) const;

    };//class Iterator


    // Postcondition: An iterator positioned at the head of
    //                the Linked container has been returned.
    Iterator Begin() const;

    // Postcondition: An iterator positioned just AFTER the
    //                tail of the Linked container has been
    //                returned. NOT the position at the tail!
    Iterator End() const;

    /*******new method*********/
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

/***** implementation of -- *****/
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
    size = 0;
}

/**********/
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
int list<T>::getLength() const {
    return size;
}


template<class T>
bool list<T>::isEmpty() const {
    return size == 0;
}


template<class T>
void list<T>::addHead(const T &newData) {    //like the "pushfront" method
    /*********adding "pre" ************/
    //please implement this
    Node *newHead = new Node;
    newHead->data = newData;
    newHead->next = head;
    if (head != NULL) {
        head->pre = newHead;
    }
    head = newHead;
    size++;
}


#endif

