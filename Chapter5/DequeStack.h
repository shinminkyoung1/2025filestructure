#ifndef DEQUESTACK_H_
#define DEQUESTACK_H_

#include <iostream>
#include "LinkedDeque.h"
#include "DequeException.h"

using namespace std;

typedef string Elem;

class DequeStack {
private:
    LinkedDeque D;

public:
    DequeStack() : D() {}

    int size() const {
        return D.size();
    }

    bool empty() const {
        return D.empty();
    }

    const Elem& top() const {
        return D.front();
    }

    void push(const Elem& e) {
        D.insertFront(e);
    }

    void pop() {
        D.removeFront();
    }
};

#endif