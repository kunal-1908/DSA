#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printarray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isunique(vector<int>& arr) {
    int hash[1000] = {0}; // Initialize the hash array to 0
    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }

    vector<int> freq; // Create a vector to store the frequencies
    for (int i = 0; i < 1000; i++) {
        if (hash[i] != 0) {
            freq.push_back(hash[i]); // Add non-zero frequencies to the vector
        }
    }

    sort(freq.begin(), freq.end()); // Sort the frequency vector
    for (int i = 0; i < freq.size() - 1; i++) { // Check for duplicates
        if (freq[i] == freq[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 9, 9, 9, 9, 9, 9, 9};
    printarray(arr);
    if (isunique(arr)) {
        cout << "all frequencies are unique." << endl;
    } else {
        cout << "not unique." << endl;
    }
    return 0;
}
