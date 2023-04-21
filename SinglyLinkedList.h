#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

// Forward declaration of SinglyLinkedList as a template
template<typename T>
class SinglyLinkedList;

template<typename T>
class Node 
{
    private:
        T data;
        Node<T>* next;
        Node(const T& value) {data = value; next = nullptr;}

        // possible by forward declaration as template
        friend class SinglyLinkedList<T>; 
};

template <typename T>
class SinglyLinkedList 
{
    private:
        Node<T>* head;
        int size;

        // recursive methods
        void print(const Node<T>*) const;
        void reversePrint(const Node<T>*) const;
        Node<T>* reverse(Node<T>*);

    public:
        // default constructor
        SinglyLinkedList();
        
        // destructor
        ~SinglyLinkedList();

        // copy constructor
        SinglyLinkedList(const SinglyLinkedList<T>& list);

        // assignment operator
        SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& list);

        // in-line
        bool empty() const {return head == nullptr;}
        Node<T>* getHead() const {return head;}
        int getSize() {return size;}

        // add items
        void addEnd(const T& value);
        void addFront(const T& value);
        
        // remove items
        bool removeEnd();
        bool removeFront();
        bool removeNode(const T& value);
        bool removeDuplicates();

        // print items
        void print();
        void reversePrint();

        // modify order
        void reverse();        
};

#endif