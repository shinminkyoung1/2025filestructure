#include <iostream>
#include <set>
#include <string>
using namespace std;

// key-value 저장
struct Entry {
    int key;
    char value;
    // 오름차순 정렬
    bool operator<(const Entry& other) const {
        return key < other.key;
    }
};

int main() {
    multiset<Entry> pq;

    pq.insert({5, 'a'});
    pq.insert({4, 'b'});
    pq.insert({7, 'i'});
    pq.insert({1, 'd'});

    // removeMin()
    auto it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    pq.insert({3, 'j'});
    pq.insert({6, 'c'});

    it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    pq.insert({8, 'g'});

    it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    pq.insert({2, 'h'});

    it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    it = pq.begin();
    cout << "removeMin(): (" << it->key << ", " << it->value << ")\n";
    pq.erase(it);

    // 최종 상태 (output)
    cout << "Output:\n";
    for (const auto& e : pq) {
        cout << "(" << e.key << ", " << e.value << ")\n";
    }

    return 0;
}
