#ifndef ARRAYVECTOR_H_
#define ARRAYVECTOR_H_

#include <iostream>
#include "VectorException.h"

using namespace std;

typedef int Elem;

class ArrayVector {
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem& operator[](int i);
    const Elem& operator[](int i) const; // const version
    Elem& at(int i);
    void erase(int i);
    void insert(int i, const Elem& e);
    void set(int i, const Elem& e);
    void reserve(int N);
    void display() const;

private:
    int capacity;
    int n;
    Elem* A;

public:
    class Iterator {
    private:
        const ArrayVector* vec;
        int index;

    public:
        Iterator(const ArrayVector* v, int i) : vec(v), index(i) {}

        Elem& operator*() {
            return const_cast<Elem&>((*vec)[index]);  // const 해제하여 쓰기 접근
        }

        const Elem& operator*() const {
            return (*vec)[index];  // 읽기 접근
        }

        bool operator==(const Iterator& other) const {
            return vec == other.vec && index == other.index;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        Iterator& operator--() {
            --index;
            return *this;
        }
    };

    Iterator begin() const { return Iterator(this, 0); }
    Iterator end() const { return Iterator(this, size()); }
};

#endif /* ARRAYVECTOR_H_ */
