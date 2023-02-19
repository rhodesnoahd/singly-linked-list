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
        Node(const T& _d) {data = _d; next = nullptr;}

        // possible by forward declaration as template
        friend class SinglyLinkedList<T>; 
};

template <typename T>
class SinglyLinkedList 
{
    private:
        Node<T>* head;
        int size;

    public:
        SinglyLinkedList(); // default constructor
        ~SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList<T>& _sll); // copy constructor
        SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& _sll); // assignment operator

        bool empty() const {return head == nullptr;}
        bool removeFront();
        bool removeNode(const T& _d);
        bool removeEnd();
        bool removeDuplicates();
        

        const T& getData(const Node<T>* _n) const {return _n->data;}
        const T& getData() const {return head->data;}

        void addFront(const T& _d);
        void addEnd(const T& _d);

        void reverse();
        Node<T>* getHead() const {return head;}
        Node<T>* reverse(Node<T>* _n);

        void print();
        void print(const Node<T>* n) const;
        void reversePrint(const Node<T>* _n) const;

        /** Add the following:
         * removeDuplicates
         * removeNodeRecur
         * sorts: merge, insertion, bubble, quick
         */
};

#endif