
#include <iostream>

#include "DequeException.h"
#include "LinkedDeque.h"

using namespace std;

LinkedDeque::LinkedDeque()			// constructor
    : n(0) {}

int LinkedDeque::size() const
	{ return n; }

bool LinkedDeque::empty() const		// is list empty?
    { return (n == 0); }

const Elem& LinkedDeque::front() const {
	  if (empty())
	    throw DequeEmpty("front of empty deque");
	  return D.front();
}

const Elem& LinkedDeque::back() const {
	  if (empty())
	    throw DequeEmpty("back of empty deque");		// get back element
      return D.back();
}


void LinkedDeque::insertFront(const Elem& e) {
  D.addFront(e);
  n++;
}
						// insert new last element
void LinkedDeque::insertBack(const Elem& e) {
  D.addBack(e);
  n++;
}
						// remove first element
void LinkedDeque::removeFront() {
  if (empty())
    throw DequeEmpty("removeFront of empty deque");
  D.removeFront();
  n--;
}
						// remove last element
void LinkedDeque::removeBack() {
  if (empty())
    throw DequeEmpty("removeBack of empty deque");
  D.removeBack();
  n--;
}



