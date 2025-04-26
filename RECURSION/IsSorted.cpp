#include<iostream>
using namespace std;

bool issorted(int arr[], int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    if(arr[n-2] > arr[n-1]) {
        return false;
    }
    return issorted(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(issorted(arr, n)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    return 0;
}
