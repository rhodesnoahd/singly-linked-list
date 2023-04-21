#include "SinglyLinkedList.h"

// default constructor with initializer list
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head(nullptr),
      size(0)
    {};

//copy constructor
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& list)
{
    if(list.empty()) {SinglyLinkedList(); return;}
    
    size = list.size;
    Node<T>* toCopy = list.head;
    Node<T>* n = new Node<T>(toCopy->data);
    this->head = n;
    Node<T>* prev = this->head;
    
    while(toCopy->next != nullptr)
    {
        toCopy = toCopy->next;
        Node<T>* cur = new Node<T>(toCopy->data);
        prev->next = cur;
        prev = prev->next;
    }
}

// assignment operator
template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& list)
{
    // check self assignment
    if (this == &list) {return *this;}
    head = list.head;
    size = list.size;
    return *this;
}

// destructor
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while(!empty()) {removeFront();}
}

template<typename T>
void SinglyLinkedList<T>::addEnd(const T& value)
{
    if(empty()) {addFront(value); return;}

    Node<T>* cur = head;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    Node<T>* n = new Node<T>(value);
    cur->next = n;
    ++size;
}

template<typename T>
void SinglyLinkedList<T>::addFront(const T& value)
{
    Node<T>* n = new Node<T>(value);
    n->next = head;
    head = n;
    ++size;
}

template<typename T>
bool SinglyLinkedList<T>::removeFront()
{
    if(empty()) {return false;}
    Node<T>* old = head;
    head = old->next;
    delete old;
    --size;
    return true;
}

template <typename T>
bool SinglyLinkedList<T>::removeNode(const T& value)
{
    if(empty()) {return false;}
    Node<T>* cur = head;
    if(value == head->data)
    {
        head = head->next;
        delete cur;
        --size;
        return true;
    }
    Node<T>* prev = cur;
    cur = cur->next;
    while(cur != nullptr)
    {
        if(value == cur->data)
        {
            prev->next = cur->next;
            delete cur;
            --size;
            return true;
        }
        prev = prev->next;
        cur = cur->next;
    }
    return false;
}

template<typename T>
bool SinglyLinkedList<T>::removeEnd()
{
    if(empty()) {return false;}
    if(head->next == nullptr) {return removeFront();}
    Node<T>* prev = head;
    Node<T>* cur = head->next;
    while(cur->next != nullptr)
    {
        cur = cur->next;
        prev = prev->next;
    }
    prev->next = nullptr;
    delete cur;
    --size;
    return true;
}

template<typename T>
bool SinglyLinkedList<T>::removeDuplicates()
{
    if(empty() || size == 1) {std::cout << "no duplicates\n"; return false;}
    
    Node<T>* cur = head;
    Node<T>* linker = cur;
    Node<T>* toCheck = nullptr;
    while (cur != nullptr)
    {   
        toCheck = cur->next;
        while (toCheck != nullptr)
        {
            if (cur->data == toCheck->data)
            {
                Node<T>* duplicate = toCheck;
                linker->next = toCheck->next;
                delete duplicate;
                size--;
                toCheck = linker->next;
            } 
            else 
            {
                linker = toCheck;
                toCheck = toCheck->next;
            }
        }
        cur = cur->next;
        linker = cur;
    }

    return true;
}

// private method
template<typename T>
void SinglyLinkedList<T>::print(const Node<T>* node) const
{
    if(node == nullptr) {return;}
    if(node == head) {std::cout << "[";}
    std::cout << node->data;
    if(node->next != nullptr) {std::cout << ", ";}
    else {std::cout << "]\n";}
    print(node->next);
}

template<typename T>
void SinglyLinkedList<T>::print()
{
    print(head);
}

// private method
template<typename T>
void SinglyLinkedList<T>::reversePrint(const Node<T>* node) const
{
    if(node == nullptr) {return;}
    reversePrint(node->next);
    if(node->next == nullptr) {std::cout << "[";}
    std::cout << node->data;
    if(node != head) {std::cout << ", ";}
    else {std::cout << "]\n";}
}

template<typename T>
void SinglyLinkedList<T>::reversePrint()
{
    reversePrint(head);
}

// private method
template<typename T>
Node<T>* SinglyLinkedList<T>::reverse(Node<T>* node)
{
    if(node->next == nullptr) 
    {
        head = node;
        return head;
    }
    Node<T>* q = reverse(node->next);
    q->next = node;
    node->next = nullptr;
    return node;
}

template<typename T>
void SinglyLinkedList<T>::reverse()
{
    reverse(head);
}
