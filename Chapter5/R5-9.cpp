#include <iostream>
#include "DequeQueue.h" // Deque으로 Queue 구현되어 있음

using namespace std;

int main() {
    DequeQueue q;

    q.enqueue("5"); // [5]
    q.enqueue("3"); // [5, 3]
    cout << q.front() << " "; q.dequeue(); // 5, [3]
    q.enqueue("2"); // [3, 2]
    q.enqueue("8"); // [3, 2, 8]
    cout << q.front() << " "; q.dequeue(); // 3, [2, 8]
    cout << q.front() << " "; q.dequeue(); // 2, [8]
    q.enqueue("9"); // [8, 9]
    q.enqueue("1"); // [8, 9, 1]
    cout << q.front() << " "; q.dequeue(); // 8, [9, 1]
    q.enqueue("7"); // [9, 1, 7]
    q.enqueue("6"); // [9, 1, 7, 6]
    cout << q.front() << " "; q.dequeue(); // 9, [1, 7, 6]
    cout << q.front() << " "; q.dequeue(); // 1, [7, 6]
    q.enqueue("4"); // [7, 6, 4]
    cout << q.front() << " "; q.dequeue(); // 7, [6, 4]
    cout << q.front() << " "; q.dequeue(); // 6, [4]

    cout << endl;
    return 0;
}