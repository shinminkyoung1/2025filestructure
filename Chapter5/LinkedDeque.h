
#ifndef LINKEDDEQUE_H_
#define LINKEDDEQUE_H_

#include <iostream>
#include <string>
#include "DequeException.h"
#include "DLinkedList.h"

using namespace std;

typedef string Elem;				// deque element type
class LinkedDeque {					// deque as doubly linked list
public:
  LinkedDeque();					// constructor
  int size() const;					// number of items in the deque
  bool empty() const;				// is the deque empty?
  const Elem& front() const; 	// the first element
  const Elem& back() const;	// the last element
  void insertFront(const Elem& e);				// insert new first element
  void insertBack(const Elem& e);				// insert new last element
  void removeFront();			// remove first element
  void removeBack();			// remove last element
private:							// member data
  DLinkedList D;					// linked list of elements
  int n;							// number of elements
};

#endif /* LINKEDDEQUE_H_ */
