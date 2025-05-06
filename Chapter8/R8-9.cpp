#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // 최솟값 인덱스 찾기
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // i와 최솟값 위치 교환
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }

        // 현재 단계 출력
        cout << "Pass " << i + 1 << ": ";
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

    selectionSort(arr);

    cout << "Sorted: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
