#ifndef DEQUEQUEUE_H_
#define DEQUEQUEUE_H_

#include "LinkedDeque.h"
#include "DequeException.h"

class DequeQueue {
private:
    LinkedDeque D;

public:
    DequeQueue() : D() {}

    int size() const { return D.size(); }

    bool empty() const { return D.empty(); }

    const Elem& front() const {
        return D.front();  // 큐는 front에서 조회
    }

    void enqueue(const Elem& e) {
        D.insertBack(e);   // 큐는 뒤에 삽입
    }

    void dequeue() {
        D.removeFront();   // 큐는 앞에서 제거
    }
};

#endif