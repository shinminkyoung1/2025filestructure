#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

int hashFunction(int key) {
    return (3 * key + 5) % TABLE_SIZE;
}

int main() {
    vector<int> table(TABLE_SIZE, -1);  // -1은 빈 슬롯을 의미
    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    for (int k : keys) {
        int h = hashFunction(k);
        int index = h;
        bool inserted = false;

        for (int i = 0; i < TABLE_SIZE; ++i) {
            index = (h + i * i) % TABLE_SIZE;
            if (table[index] == -1) {
                table[index] = k;
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            cout << "fails: " << k << endl;
            break;  // 실패 시 종료
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
