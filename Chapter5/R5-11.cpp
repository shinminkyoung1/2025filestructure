#include <iostream>
#include "LinkedDeque.h"
#include "DequeQueue.h"

using namespace std;

int main() {
    LinkedDeque D;
    DequeQueue Q;

    // 초기 Deque 세팅
    D.insertBack("1");
    D.insertBack("2");
    D.insertBack("3");
    D.insertBack("4");
    D.insertBack("5");
    D.insertBack("6");
    D.insertBack("7");
    D.insertBack("8");

    // 앞의 3개를 Queue로 이동 (1, 2, 3)
    for (int i = 0; i < 3; i++) {
        Q.enqueue(D.front());
        D.removeFront();
    }

    // 다시 D의 뒤에 넣음
    for (int i = 0; i < 3; i++) {
        D.insertBack(Q.front());
        Q.dequeue();
    }

    // 4와 5를 꺼내서 순서 바꿔 삽입
    string a = D.front(); D.removeFront();  // a = 4
    string b = D.front(); D.removeFront();  // b = 5
    D.insertBack(b); // 5 먼저
    D.insertBack(a); // 4 나중에

    // 나머지 3개를 앞에서 뒤로 순회
    for (int i = 0; i < 3; i++) {
        D.insertBack(D.front());
        D.removeFront();
    }

    while (!D.empty()) {
        cout << D.front() << " ";
        D.removeFront();
    }

    cout << endl;
    return 0;
}
