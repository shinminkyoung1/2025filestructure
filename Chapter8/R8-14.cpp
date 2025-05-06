#include <iostream>
#include <vector>
using namespace std;

void heapinit(vector<int>& arr, int n, int i) {
    int largest = i;       // 루트
    int left = 2 * i + 1;  // 왼쪽 자식
    int right = 2 * i + 2; // 오른쪽 자식

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapinit(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 최대 힙 만들기
    for (int i = n / 2 - 1; i >= 0; i--)
        heapinit(arr, n, i);

    cout << "max heap:\n";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // 힙 정렬 수행
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // 루트와 끝 노드 교환
        heapinit(arr, i, 0);    // 힙 크기 i로 줄이고 루트 heapinit

        cout << "index " << i << ": ";
        for (int val : arr) cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {2, 5, 16, 4, 10, 23, 39, 18, 26, 15};

    cout << "Initial array:\n";
    for (int val : arr) cout << val << " ";
    cout << endl;

    heapSort(arr);

    cout << "output: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}
