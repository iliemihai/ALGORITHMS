#ifndef STACK__H
#define STACK__H

template<typename T, int N>
class Stack {
private:
  T stackArray[N];
  int topL;
public:
  Stack()
  {
    topL = -1;
  }
  ~Stack(){}
  virtual void push(T x)
  {
    topL++;
    stackArray[topL] = x;
  }

  virtual void pop()
  {
    stackArray[topL] = 0;
    topL--;
  }

  virtual T peek()
  {
    return stackArray[topL];
  }

  virtual bool isEmpty()
  {
    return topL == -1;
  }
};

#endif
