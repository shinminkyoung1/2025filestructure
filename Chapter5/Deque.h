
#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include "DequeException.h"
#include "LinkedDeque.h"

using namespace std;

typedef string Elem;				// element type
class DequeStack {					// stack as a deque
public:
    DequeStack();					// constructor
    int size() const;				// number of elements
    bool empty() const;				// is the stack empty?
    const Elem& top() const;	// the top element
    void push(const Elem& e);			// push element onto stack
    void pop();		// pop the stack
private:
    LinkedDeque D;					// deque of elements
};

DequeStack::DequeStack()			// constructor
    : D() { }
  									// number of elements
int DequeStack::size() const
    { return D.size(); }
  									// is the stack empty?
bool DequeStack::empty() const
    { return D.empty(); }
  									// the top element
const Elem& DequeStack::top() const {
    if (empty())
      throw StackEmpty("top of empty stack");
    return D.front();
}
  									// push element onto stack
void DequeStack::push(const Elem& e)
    { D.insertFront(e); }
  									// pop the stack
void DequeStack::pop()
{
    if (empty())
      throw StackEmpty("pop of empty stack");
    D.removeFront();
}

#endif /* DEQUE_H_ */
