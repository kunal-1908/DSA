#include<iostream>
#include<vector>
using namespace std;

void printarray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Selectionsort(vector<int>& arr, int n) {
    if (n == 0 || n == 1) {
        return;
    }
    int indexofmax = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[indexofmax]) {
            indexofmax = i;
        }
    }
    if (indexofmax != n - 1) {
        swap(arr[n - 1], arr[indexofmax]);
    }
    Selectionsort(arr, n - 1);
}

int main() {
    vector<int> arr = {2, 9, 1, 3, 90, 30, 20};
    int n = arr.size();

    cout << "Original array: ";
    printarray(arr);

    Selectionsort(arr, n);

    cout << "Sorted array: ";
    printarray(arr);

    return 0;
}
