#include <iostream>
#include "LinkedDeque.h"
#include "DequeStack.h"

using namespace std;

int main() {
    LinkedDeque D;
    DequeStack S;

    // 초기 Deque 세팅
    D.insertBack("1");
    D.insertBack("2");
    D.insertBack("3");
    D.insertBack("4");
    D.insertBack("5");
    D.insertBack("6");
    D.insertBack("7");
    D.insertBack("8");

    // 앞의 3개를 Stack으로 이동 (1, 2, 3)
    for (int i = 0; i < 3; i++) {
        S.push(D.front());
        D.removeFront();
    }

    // 다시 D의 뒤에 넣음 
    string a = D.front(); D.removeFront(); // a = 4
    string b = D.front(); D.removeFront(); // b = 5
    D.insertBack(b); // 5
    D.insertBack(a); // 4

    // 나머지 3개를 앞에서 뒤로 순회
    for (int i = 0; i < 3; i++) {
        D.insertBack(D.front());
        D.removeFront();
    }

    // 1, 2, 3 순서 유지하기 위한 반복문
    for (int i = 0; i < 3; i++) {
        D.insertFront(S.top());
        S.pop();
    }

    while (!D.empty()) {
        cout << D.front() << " ";
        D.removeFront();
    }

    cout << endl;
    return 0;
}
