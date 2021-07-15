#pragma once
#include <iostream>
template <class ElemType>
class Node
{
public:
    ElemType data;
    Node<ElemType>* next;
    Node<ElemType>* prev;
    Node(ElemType item)
    { // init node object
        data = item;
        prev = NULL;
        next = NULL;
    }
};

// 实现一个双向链表
template <class ElemType>
class List
{
private:
    Node<ElemType>* header;  // head node
    Node<ElemType>* trailer; // tail node
    int size = 0;            // size of List
public:
    List()
    {
        header->next = trailer;
        header->prev = NULL;
        trailer->prev = header;
        trailer->next = NULL;
    }
    ~List() { clear(); }
    bool empty() { return size == 0; } // if empty, return true;
    int getSize() { return this->size; }
    void clear(); // remove all the nodes
    Node<ElemType>* getNode(int pos);
    Node<ElemType>* first()
    {
        if (!size)
            return NULL;
        else
            return header->next;
    }
    Node<ElemType>* last()
    {
        if (!size)
            return NULL;
        else
            return trailer->prev;
    }
    void insertAsFirst(ElemType const& item);
    void insertAsLast(ElemType const& item);
    void insertAsPred(int pos, ElemType const& item);
    void insertAsSucc(int pos, ElemType const& item);
    void diaplay(); // display all the elements;
    ElemType remove(Node<ElemType>* p);
    Node<ElemType>* find(ElemType const& item);
};

template <class ElemType>
void List<ElemType>::insertAsFirst(const ElemType& item)
{
    Node<ElemType> s(item); // init a new node
    s.next = header->next;
    s.prev = header;
    header->next->prev = s;
    header->next = s;
    size++;
}

template <class ElemType>
void List<ElemType>::insertAsLast(const ElemType& item)
{
    Node<ElemType> s(item); // init a new node
    s.next = trailer;
    s.prev = trailer->prev;
    trailer->prev->next = s;
    trailer->prev = s;
    size++;
}

template <class ElemType>
Node<ElemType>* List<ElemType>::getNode(int pos)
{
    if (pos > size)
        return NULL;
    Node<ElemType>* tmp = header;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;
    return tmp;
}

template <class ElemType>
void List<ElemType>::insertAsSucc(int pos, const ElemType& item)
{
    if (pos > size)
    {
        cout << "Out of rebound" << endl;
        return;
    }
    Node<ElemType>* p = getNode(pos);
    Node<ElemType> s(item);
    // insert s succeed p;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    size++;
}

template <class ElemType>
void List<ElemType>::insertAsPred(int pos, const ElemType& item)
{
    if (pos > size)
    {
        cout << "Out of rebound" << endl;
        return;
    }
    Node<ElemType>* p = getNode(pos);
    Node<ElemType> s(item);
    // insert s before p;
    s->prev = p->prev;
    s->next = p;
    p->prev->next = s;
    p->prev = s;
    size++;
}

template <class ElemType>
ElemType List<ElemType>::remove(Node<ElemType>* p)
{
    // p must point to a node in the list
    // remove p and return
    ElemType data = p->data;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    size--;
    return data;
}

template <class ElemType>
void List<ElemType>::diaplay()
{
    Node<ElemType> p = header;
    while (p->next != NULL)
    {
        cout << p->next->data;
        p = p->next;
    }
}

template <class ElemType>
void List<ElemType>::clear()
{
    Node<ElemType> p = first();
    while (!size)
    {
        remove(p);
        p = first();
    }
}

template <class ElemType>
Node<ElemType>* List<ElemType>::find(ElemType const& item)
{
    if (empty())
        return NULL;
    Node<ElemType>* p = last();
    for (int i = size; i--; i > 0)
    {
        if (p->data == item)
            return p;
        p = p->prev;
    }
    return NULL;
}