#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Adjust hash size for negative values, assuming range [-1000, 1000]
        vector<int> hash(2001, 0); // Adjusted to include indices for -1000 to 1000

        // Count frequencies of elements in arr
        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++; // Shift indices to handle negative numbers
        }

        // Extract non-zero frequencies
        vector<int> freq;
        for (int i = 0; i < 2001; i++) {
            if (hash[i] > 0) {
                freq.push_back(hash[i]);
            }
        }

        // Sort the frequencies
        sort(freq.begin(), freq.end());

        // Check for duplicate frequencies
        for (int i = 0; i < freq.size() - 1; i++) {
            if (freq[i] == freq[i + 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test case 1: ";
    if (solution.uniqueOccurrences(arr1)) {
        cout << "All frequencies are unique." << endl;
    } else {
        cout << "Frequencies are not unique." << endl;
    }

    // Test case 2
    vector<int> arr2 = {1, 2};
    cout << "Test case 2: ";
    if (solution.uniqueOccurrences(arr2)) {
        cout << "All frequencies are unique." << endl;
    } else {
        cout << "Frequencies are not unique." << endl;
    }

    // Test case 3
    vector<int> arr3 = {-1, -1, -2, -2, -3};
    cout << "Test case 3: ";
    if (solution.uniqueOccurrences(arr3)) {
        cout << "All frequencies are unique." << endl;
    } else {
        cout << "Frequencies are not unique." << endl;
    }

    return 0;
}
