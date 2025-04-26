#include<iostream>
#include<vector>
using namespace std;

int rotatedandsorted(vector<int> arr, int n) {
    int count = 0;

    // Check the number of times the array goes from a larger value to a smaller value
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            count++;
        }
    }

    // Also check if the last element is greater than the first element (rotation condition)
    if (arr[n - 1] > arr[0]) {
        count++;
    }

    return count;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80,90,100};  // Sorted and not rotated
    int n = arr.size();
    
    int count = rotatedandsorted(arr, n);  // Check if the array is rotated and sorted
    
    cout << "Number of places where the array breaks sorting: " << count << endl;
    if (count <= 1) {
        cout << "true" << endl;  // Array is sorted and rotated
    } else {
        cout << "false" << endl;  // Array is not sorted and rotated
    }

    return 0;
}
