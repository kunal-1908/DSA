#include<iostream>
using namespace std;

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sorrt(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {0, 1, 2, 0, 0, 1, 2, 2, 0, 0, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printarray(arr, n);  // Print the unsorted array
    sorrt(arr, n);  // Sort the array
    printarray(arr, n);  // Print the sorted array

    return 0;
}
