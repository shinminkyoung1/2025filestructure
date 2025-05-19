#include <iostream>
#include "HashMap.h"

using namespace std;

class IntHash {
public:
    int operator()(int i) const {
        return (3 * i + 5);
    }
};

template <typename K, typename V, typename H>
void displayBuckets(const HashMap<K, V, H>& map) {
    for (int i = 0; i < 11; ++i) {
        cout << "[" << i << "]: ";
        auto bkt = map.B.begin() + i; 
        for (auto it = bkt->begin(); it != bkt->end(); ++it) {
            cout << it->key() << " ";
        }
        cout << endl;
    }
}

int main() {
    HashMap<int, string, IntHash> map(11); 

    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    for (int k : keys) {
        map.put(k, "x");  // value는 임의의 값을 삽입
    }

    displayBuckets(map);

    return 0;
}
