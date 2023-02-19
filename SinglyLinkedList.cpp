#include "SinglyLinkedList.h"

// default constructor with initializer list
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head(nullptr),
      size(0)
    {};

//copy constructor
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& _sll)
{
    if(_sll.empty()) {SinglyLinkedList(); return;}
    
    size = _sll.size;
    Node<T>* toCopy = _sll.head;
    Node<T>* n = new Node<T>(toCopy->data);
    head = n;
    Node<T>* prev = head;
    
    while(toCopy->next != nullptr)
    {
        toCopy = toCopy->next;
        Node<T>* cur = new Node<T>(toCopy->data);
        prev->next = cur;
        prev = prev->next;
        // cur = cur->next;
    }
}

// assignment operator
template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& _sll)
{
    if(_sll.empty()) {SinglyLinkedList(); return *this;}
    if(this != &_sll)
    {
        size = _sll.size;
        Node<T>* toCopy = _sll.head;
        Node<T>* n = new Node<T>(toCopy->data);
        head = n;
        Node<T>* prev = head;
        
        while(toCopy->next != nullptr)
        {
            toCopy = toCopy->next;
            Node<T>* cur = new Node<T>(toCopy->data);
            prev->next = cur;
            prev = prev->next;
            // cur = cur->next;
        }
    }
    return *this;
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
bool SinglyLinkedList<T>::removeNode(const T& _d)
{
    if(empty()) {return false;}
    Node<T>* cur = head;
    if(_d == head->data)
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
        if(_d == cur->data)
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
    if(empty() || head->next == nullptr) {return false;}
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    Node<T>* next = head->next;
    while(cur->next != nullptr)
    {
        if(cur->data == next->data)
        {
            cur->next = next->next;
            Node<T>* duplicate = next;
            prev = cur;
            cur = cur->next;
            next = next->next;
            delete duplicate;
        }
    }
    return true;
}

// destructor
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while(!empty()) {removeFront();}
}

template<typename T>
void SinglyLinkedList<T>::addFront(const T& _d)
{
    Node<T>* n = new Node<T>(_d);
    n->next = head;
    head = n;
    ++size;
}

template<typename T>
void SinglyLinkedList<T>::addEnd(const T& _d)
{
    if(empty()) {addFront(_d); return;}

    Node<T>* cur = head;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    Node<T>* n = new Node<T>(_d);
    cur->next = n;
    ++size;
}

template<typename T>
void SinglyLinkedList<T>::reverse()
{
    if(empty() || head->next == nullptr) {return;}
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    Node<T>* next = nullptr;
    while(cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

template<typename T>
Node<T>* SinglyLinkedList<T>::reverse(Node<T>* _n)
{
    if(_n->next == nullptr) 
    {
        head = _n;
        return head;
    }
    Node<T>* q = reverse(_n->next);
    q->next = _n;
    _n->next = nullptr;
    return _n;
}

template<typename T>
void SinglyLinkedList<T>::print()
{
    if(empty()) {return;}
    Node<T>* cur = head;
    
    while(cur->next != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}


template<typename T>
void SinglyLinkedList<T>::print(const Node<T>* _n) const
{
    if(_n == nullptr) {return;}
    if(_n == head) {std::cout << "Forward printed list: {";}
    std::cout << _n->data;
    if(_n->next != nullptr) {std::cout << ", ";}
    else {std::cout << "}\n";}
    print(_n->next);
}

template<typename T>
void SinglyLinkedList<T>::reversePrint(const Node<T>* _n) const
{
    if(_n == nullptr) {return;} // n or n->next == nullptr
    reversePrint(_n->next);
    if(_n->next == nullptr) {std::cout << "Reverse printed list: {";}
    std::cout << _n->data;
    if(_n != head) {std::cout << ", ";}
    else {std::cout << "}\n";}
}

// add more!