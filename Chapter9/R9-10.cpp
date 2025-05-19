#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

int primaryHash(int key) {
    return (3 * key + 5) % TABLE_SIZE;
}

int secondaryHash(int key) {
    return 7 - (key % 7);
}

int main() {
    vector<int> table(TABLE_SIZE, -1);  // 해시 테이블 초기화
    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    for (int k : keys) {
        int h1 = primaryHash(k);
        int h2 = secondaryHash(k);
        int index = h1;
        bool inserted = false;

        for (int i = 0; i < TABLE_SIZE; ++i) {
            index = (h1 + i * h2) % TABLE_SIZE;
            if (table[index] == -1) {
                table[index] = k;
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            cout << "삽입 실패: " << k << endl;
            break;
        }
    }

    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << i << "]: ";
        if (table[i] != -1)
            cout << table[i];
        cout << endl;
    }

    return 0;
}
