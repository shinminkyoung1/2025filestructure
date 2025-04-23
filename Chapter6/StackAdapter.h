#ifndef STACKADAPTER_H_
#define STACKADAPTER_H_

#include "ArrayVector.h"
#include "VectorException.h"

class StackAdapter {
private:
    ArrayVector vec;

public:
    StackAdapter() {}

    void push(const Elem& e) {
        vec.insert(vec.size(), e);
    }

    void pop() {
        if (vec.empty())
            throw IndexOutOfBounds("Stack is empty in pop()");
        vec.erase(vec.size() - 1);
    }

    Elem& top() {
        if (vec.empty())
            throw IndexOutOfBounds("Stack is empty in top()");
        return vec.at(vec.size() - 1);
    }

    int size() const {
        return vec.size();
    }

    bool empty() const {
        return vec.empty();
    }
};

#endif