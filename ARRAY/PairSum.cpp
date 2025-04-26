#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printarray(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> pairsum(vector<int>& arr, int m, int key) {
    vector<vector<int>> ans;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (arr[i] + arr[j] == key) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
   
    vector<int> arr = {1, 2, 3, 6, 9, 3, 10, 4};
    int m = arr.size();
    int key = 5;

    vector<vector<int>> ans = pairsum(arr, m, key);
    printarray(ans);
    return 0;
}
