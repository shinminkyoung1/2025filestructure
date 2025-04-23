#include <iostream>
#include "VectorException.h"
#include "ArrayVector.h"

using namespace std;

ArrayVector::ArrayVector()
    : capacity(0), n(0), A(NULL) { }

int ArrayVector::size() const {
    return n;
}

bool ArrayVector::empty() const {
    return size() == 0;
}

Elem& ArrayVector::operator[](int i) {
    return A[i];
}

const Elem& ArrayVector::operator[](int i) const {
    return A[i];
}

Elem& ArrayVector::at(int i) {
    if (i < 0 || i >= n)
        throw IndexOutOfBounds("illegal index in function at()");
    return A[i];
}

void ArrayVector::reserve(int N) {
    if (capacity >= N) return;
    Elem* B = new Elem[N];
    for (int j = 0; j < n; j++)
        B[j] = A[j];
    if (A != NULL) delete[] A;
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity) {
        cout << "increased by double (" << n << ") : " << capacity << " -> " << 2 * capacity << endl;
        reserve(max(1, 2 * capacity));
    }
    for (int j = n - 1; j >= i; j--)
        A[j + 1] = A[j];
    A[i] = e;
    n++;
}

void ArrayVector::set(int i, const Elem& e) {
    if (i < 0 || i >= n)
        throw IndexOutOfBounds("illegal index in function at()");
    A[i] = e;
}

void ArrayVector::erase(int i) {
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    n--;
}

void ArrayVector::display() const {
    cout << "Array Vector : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    ArrayVector v;

    v.insert(0, 7); v.display();
    v.insert(0, 4); v.display();
    cout << v.at(1) << endl;
    v.insert(2, 2);  v.display();

    try {
        v.at(3);  // out-of-bounds 테스트
    } catch (IndexOutOfBounds& e) {
        cout << "Exception catch : " << e.getMessage() << endl;
    }

    v.erase(1);     v.display();
    v.insert(1, 5); v.display();
    v.insert(1, 3); v.display();
    v.insert(4, 9); v.display();
    cout << v.at(2) << endl;
    v.set(3, 8);     v.display();

    cout << "Forward Traversal 테스트" << endl;
    for (ArrayVector::Iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse Traversal 테스트" << endl;
    ArrayVector::Iterator it = v.end();
    for (int i = 0; i < v.size(); ++i) {
        --it;
        cout << *it << " ";
    }
    cout << endl;

    cout << "Iterator Equality 테스트" << endl;
    ArrayVector::Iterator it1 = v.begin();
    ArrayVector::Iterator it2 = v.begin();
    ++it2;
    cout << "it1 == it2? " << (it1 == it2 ? "true" : "false") << endl;
    ++it1;
    cout << "After ++it1, it1 == it2? " << (it1 == it2 ? "true" : "false") << endl;

    return EXIT_SUCCESS;
}
