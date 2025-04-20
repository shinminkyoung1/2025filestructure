#include <iostream>
#include <queue>
#include <string>

using namespace std;

class StackWithQueues {
private:
    queue<string> q1;
    queue<string> q2;

public:
    bool empty() const {
        return q1.empty();
    }

    int size() const {
        return q1.size();
    }

    void push(const string& x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    string top() const {
        if (!q1.empty()) {
            return q1.front();
        }
        return "EMPTY";
    }
};
