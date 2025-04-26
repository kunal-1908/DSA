#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findDuplicates(const vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> duplicates;

    for (int num : arr) {
        if (seen.count(num) > 0) {
            duplicates.push_back(num);
        } else {
            seen.insert(num);
        }
    }

    return duplicates;
}

int main() {
    vector<int> arr = {4, 4, 4, 4, 3, 3, 3, 2, 2};

    vector<int> duplicates = findDuplicates(arr);

    if (duplicates.empty()) {
        cout << "No duplicates found." << endl;
    } else {
        cout << "Duplicates found: ";
        for (int num : duplicates) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}