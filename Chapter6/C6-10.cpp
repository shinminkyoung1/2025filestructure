#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Sequence {
private:
    vector<T> data;

public:
    void insertAtRank(int r, const T& elem) {
        if (r < 0 || r > data.size()) {
            throw out_of_range("Invalid rank for insertion");
        }
        data.insert(data.begin() + r, elem);
    }

    void display() const {
        cout << "[ ";
        for (auto e : data)
            cout << e << " ";
        cout << "]" << endl;
    }

    int size() const {
        return data.size();
    }
};

int main() {
    Sequence<int> seq; // 주어진 라인
    int n = 10; // 10번 수행 (주어진 라인)

    for (int i = 0; i < n; i++) { // 주어진 라인
        int rank = i / 2; // 수행해야 하는 것
        seq.insertAtRank(rank, i);
        cout << "After inserting " << i << " at rank " << rank << ": ";
        seq.display();
    }
    return 0;
}
