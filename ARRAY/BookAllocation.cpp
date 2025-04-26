#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a given maximum number of pages `pages` can be allocated
bool isPossible(vector<int>& arr, int n, int m, int pages) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= pages) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

// Function to find the minimum maximum number of pages using linear search
int findPages(vector<int>& arr, int n, int m) {
    int maxElement = *max_element(arr.begin(), arr.end());
    int sum = 203;

    // Linear search over the possible range of maximum pages
    for (int pages = maxElement; pages <= sum; pages++) {
        if (isPossible(arr, n, m, pages)) {
            return pages;
        }
    }

    return -1; // Return -1 if no valid allocation is found (edge case)
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;

    int result = findPages(arr, n, m);
    cout << "The minimum maximum number of pages allocated is: " << result << endl;
    return 0;
}
