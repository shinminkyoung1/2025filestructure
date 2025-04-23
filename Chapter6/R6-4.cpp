#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> A; // empty vector A 설정

    A.insert(A.begin() + 0, 4);  // (0, 4)
    A.insert(A.begin() + 0, 3);  // (0, 3) 
    A.insert(A.begin() + 0, 2);  // (0, 2)
    A.insert(A.begin() + 2, 1);  // (2, 1)
    A.insert(A.begin() + 1, 5);  // (1, 5)
    A.insert(A.begin() + 1, 6);  // (1, 6)
    A.insert(A.begin() + 3, 7);  // (3, 7)
    A.insert(A.begin() + 0, 8);  // (0, 8)

    for (int val : A) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}