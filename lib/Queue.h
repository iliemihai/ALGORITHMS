#ifndef QUEUE__H
#define QUEUE__H
#include <iostream>

template<typename T, int N>
class Queue{
private:
  int head;
  int tail;
  int size;
  T queueArray[N];

public:
  Queue(){
    this->size = 0;
    this->head = this->tail = -1;
  }
  virtual ~Queue(){}

  void enqueue(T e){
    this->head++;
    queueArray[this->head] = e;
    this->size++;
  }

  void dequeue() {
    queueArray[this->head] = 0;
    this->head--;
    this->size--;
  }

  T front() {
    return queueArray[this->head];
  }

  bool isEmpty() {
    if (this->head == this->tail)
      return true;
    return false;
  }
};

#endif
