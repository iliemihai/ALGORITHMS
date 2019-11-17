#include "DoubleLinkedList.h"

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = this->prev = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head=nullptr;
    tail=nullptr;
    numElements=0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* head){
    this->head=head;
    while(head!=nullptr){
        numElements++;
        head=head->next;
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){

}

template<typename T>
void DoublyLinkedList<T>::addLast(T data){
    Node<T>* aux = new Node<T>(data);
    if(isEmpty()) {
        head = tail = aux;
    } else {
        tail->next = aux;
        aux->prev = tail;
        tail = aux;
    }
    numElements++;
}

template<typename T>
void DoublyLinkedList<T>::addFirst(T data){
    Node<T>* aux = new Node<T>(data);
    if(isEmpty()) {
        head = tail = aux;
    } else {
        aux->next = head;
        head->prev = aux;
        head = aux;
    }
    numElements++;
}

template<typename T>
T DoublyLinkedList<T>::removeLast(){
    T data = tail->data;
    tail = tail->prev;
    if(tail==nullptr){
        head=nullptr;
    }else{
        tail->next=nullptr;
    }
    numElements--;
    return data;
}


template<typename T>
T DoublyLinkedList<T>:: removeFirst(){
    T data = head->data;
    head = head->next;
    if(head!=nullptr){
        head->prev = nullptr;
    }else{
        tail=nullptr;
    }
    numElements--;
    return data;
}

template<typename T>
bool DoublyLinkedList<T>:: isEmpty(){
    return size()==0;
}

template<typename T>
int DoublyLinkedList<T>:: size(){
    return numElements;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getHead(){
    return head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getTail(){
    return tail;
}

template class Node<int>;
template class DoublyLinkedList<int>;
