#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class StackUsingPriorityQueue {
private:
    priority_queue<pair<int, T>> pq;
    int seq = 0;  // 시퀀스 번호

public:
    void push(T x) {
        pq.push({seq++, x});
    }

    void pop() {
        if (!pq.empty()) pq.pop();
    }

    T top() {
        return pq.top().second;
    }

    bool empty() {
        return pq.empty();
    }
};

int main() {
    StackUsingPriorityQueue<string> stk;
    stk.push("a");
    stk.push("b");
    stk.push("c");

    cout << stk.top() << endl; 
    stk.pop();
    cout << stk.top() << endl; 
    stk.pop();
    cout << stk.top() << endl; 
}
