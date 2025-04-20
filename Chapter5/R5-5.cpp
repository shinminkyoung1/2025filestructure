#include <iostream>
#include "DequeStack.h"

using namespace std;

int main() {
    DequeStack s;

    s.push("5"); // [5]
    s.push("3"); // [5, 3]
    cout << s.top() << " "; 
    s.pop(); // 3, [5]

    s.push("2"); // [5, 2]
    s.push("8"); // [5, 2, 8]
    cout << s.top() << " "; 
    s.pop(); // 8, [5, 2]
    cout << s.top() << " "; 
    s.pop(); // 2, [5]

    s.push("9"); // [5, 9]
    s.push("1"); // [5, 9, 1]
    cout << s.top() << " "; 
    s.pop(); // 1, [5, 9]

    s.push("7"); // [5, 9, 7]
    s.push("6"); // [5, 9, 7, 6]
    cout << s.top() << " "; 
    s.pop(); // 6, [5, 9, 7]
    cout << s.top() << " "; 
    s.pop(); // 7, [5, 9]
    
    s.push("4"); // [5, 9, 4] 
    cout << s.top() << " "; 
    s.pop(); // 4, [5, 9]
    cout << s.top() << " "; 
    s.pop(); // 9, [5]

    cout << endl;
    return 0;
}