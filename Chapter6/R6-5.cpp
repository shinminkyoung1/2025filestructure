#include <iostream>
#include "StackAdapter.h"

using namespace std;

int main() {
    
    StackAdapter stack;

    // push() 테스트
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // top() 테스트
    cout << "Top: " << stack.top() << endl;  // 30

    // pop() 테스트
    stack.pop();
    cout << "Top after pop: " << stack.top() << endl;  // 20

    // size() 테스트
    cout << "Size: " << stack.size() << endl;  // 2

    // empty() 테스트    
    cout << "Empty: " << (stack.empty() ? "true" : "false") << endl;  

    return 0;
}