#include <iostream>
#include "LinkedDeque.h"
#include "DequeException.h"

using namespace std;

int main() {
    LinkedDeque dq;

    dq.insertFront("3"); // [3]
    dq.insertBack("8"); // [3, 8]
    dq.insertBack("9"); // [3, 8, 9]
    dq.insertFront("5"); // [5, 3, 8, 9]

    cout << dq.front() << " "; // 5
    dq.removeFront(); // [3, 8, 9]

    cout << dq.back() << " "; // 9
    dq.removeBack(); // [3, 8]

    cout << dq.front() << " "; // 3

    dq.insertBack("7"); // [3, 8, 7]

    cout << dq.front() << " "; // 3
    dq.removeFront(); // [8, 7]

    cout << dq.back() << " "; // 7

    cout << dq.back() << " "; // 7
    dq.removeBack(); // [3]

    cout << endl;
    return 0;
}