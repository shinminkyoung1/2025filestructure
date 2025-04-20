#include <iostream>
#include "StackWithQueues.h"

using namespace std;

int main() {
    StackWithQueues s;

    s.push("a");
    s.push("b");
    s.push("c");

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}
