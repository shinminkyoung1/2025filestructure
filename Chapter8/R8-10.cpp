#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // 현재 삽입할 값
        int j = i - 1;

        // key보다 큰 값은 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // 현재 단계 출력
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {22, 15, 36, 44, 10, 3, 9, 13, 29, 25};

    cout << "Initial: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    insertionSort(arr);

    cout << "Sorted: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
