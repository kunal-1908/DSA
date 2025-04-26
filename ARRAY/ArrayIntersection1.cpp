#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result; // To store the intersection
    int i = 0, j = 0;

    // Two-pointer approach to find intersection
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            // To avoid duplicates in the result
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++; // Move pointer in arr1
        } else {
            j++; // Move pointer in arr2
        }
    }

    return result;
}

int main() {
    // Input arrays
    vector<int> arr1 = {1, 2, 2, 2, 2, 3, 4, 5};
    vector<int> arr2 = {2, 2, 2, 2, 3, 4};

    // Find intersection
    vector<int> intersection = findIntersection(arr1, arr2);

    // Output the result
    cout << "Intersection: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
