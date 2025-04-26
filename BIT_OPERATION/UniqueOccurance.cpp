#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to print frequency of elements and check for unique occurrences
void printfrequencymap(const vector<int>& arr) {
    unordered_map<int, int> frequency;

    // Count the frequency of each element
    for (int i = 0; i < arr.size(); i++) {
    int num = arr[i];
    frequency[num]++;
}


    // Print the frequencies
    cout << "nums" << " : " << "frequency" << endl;
    for (const auto& entry : frequency) {
        cout << entry.first << " : " << entry.second << endl;
    }

    // Check if the occurrences are unique
    unordered_set<int> occurrenceCounts;
    for (const auto& pair : frequency) {
        occurrenceCounts.insert(pair.second);  // Insert frequency into set
    }

    // If occurrenceCounts size is the same as frequency size, all occurrences are unique
    if (occurrenceCounts.size() == frequency.size()) {
        cout << "All frequencies are unique." << endl;
    } else {
        cout << "Frequencies are not unique." << endl;
    }
}

int main() {
    vector<int> arr = {2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 5};

    // Call the function
    printfrequencymap(arr);

    return 0;
}
