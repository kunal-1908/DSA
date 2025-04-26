#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printarray(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> Tripletsum(vector<int>& arr, int m, int key) {
    vector<vector<int>> ans;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (arr[i] + arr[j] + arr[k] == key) {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);

                    sort(temp.begin(), temp.end());

                    ans.push_back(temp);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int m = arr.size();
    int key = 9;

    vector<vector<int>> ans = Tripletsum(arr, m, key);

    if (!ans.empty()) {
        printarray(ans);
    } else {
        cout << "No triplets found." << endl;
    }

    return 0;
}
