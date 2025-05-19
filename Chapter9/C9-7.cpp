#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

class LinearProbingHashTable {
private:
    vector<int> table;

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    LinearProbingHashTable() : table(TABLE_SIZE, -1) {}

    void insert(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "삽입 실패(테이블이 꽉 참)\n";
                return;
            }
        }
        table[index] = key;
    }

    bool find(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        int start = index;

        // 삭제할 키 탐색
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;  // 삭제

                // 삭제 이후 재배치
                int next = (index + 1) % TABLE_SIZE;
                while (table[next] != -1) {
                    int temp = table[next];
                    table[next] = -1;
                    insert(temp);
                    next = (next + 1) % TABLE_SIZE;
                }
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        cout << "삭제 실패: " << key << "를 찾을 수 없음.\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            if (table[i] != -1)
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    LinearProbingHashTable ht;

    int keys[] = {5, 16, 27, 38, 49};
    for (int k : keys) ht.insert(k);

    cout << "삽입 후:";
    ht.display();

    // 키 삭제
    cout << "\n키 5 삭제:";
    ht.remove(5);

    ht.display();

    // 검색 확인
    cout << "\n검색 테스트:" << endl;
    cout << "키 16 검색 결과: " << (ht.find(16) ? "존재함" : "없음") << endl;
    cout << "키 5 검색 결과: " << (ht.find(5) ? "존재함" : "없음") << endl;

    return 0;
}
