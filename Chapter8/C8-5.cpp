#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class QueueUsingPriorityQueue {
private:
    using PQElement = pair<int, T>;
    priority_queue<PQElement, vector<PQElement>, greater<PQElement>> pq;
    int seq = 0;

public:
    void enqueue(T x) {
        pq.push({seq++, x});
    }

    void dequeue() {
        if (!pq.empty()) pq.pop();
    }

    T front() {
        return pq.top().second;
    }

    bool empty() {
        return pq.empty();
    }
};

int main() {
    QueueUsingPriorityQueue<string> q;
    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");

    cout << q.front() << endl;  
    q.dequeue();
    cout << q.front() << endl;  
    q.dequeue();
    cout << q.front() << endl; 
}
