#ifndef __DOUBLE_LIST__H__
#define __DOUBLE_LIST__H__
#include <assert.h>
#include <ostream>

template<typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data);
};

template<typename T>
class DoublyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;
public:
    DoublyLinkedList();

    DoublyLinkedList(Node<T>* head);

    ~DoublyLinkedList();

    void addLast(T data);

    void addFirst(T data);

    T removeLast();

    T removeFirst();

    bool isEmpty();

    int size();

    Node<T> *getHead();

    Node<T>* getTail();

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList<U>& list);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if(list.size() > 0){
        os << "[";
        while(it->next!=nullptr){
            os<<it->data<<"<->";
            it=it->next;
        }

        os<<it->data;
        os<<"]";
    }else{
        os<<"[]";
    }
    return os;
}

#endif