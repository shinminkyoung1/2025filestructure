#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

int hashFunction(int key) {
    return (3 * key + 5) % TABLE_SIZE;
}

int main() {
    vector<int> table(TABLE_SIZE, -1); // -1: 빈 슬롯

    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    for (int k : keys) {
        int index = hashFunction(k);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "삽입 실패(해시 테이블 꽉 참): " << k << endl;
                break;
            }
        }

        if (table[index] == -1) {
            table[index] = k;
        }
    }

    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << i << "]: ";
        if (table[i] != -1) {
            cout << table[i];
        }
        cout << endl;
    }

    return 0;
}
