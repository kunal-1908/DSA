#include<iostream>
#include<vector>
using namespace std;

void printarray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printSubsets(const vector<vector<int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }
}
 void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }
vector<vector<int>> subset(vector<int>& arr) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, output, index, ans);
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 3};

    // Print original array
    cout << "Original array: ";
    printarray(arr);

    // Get and print all subsets
    vector<vector<int>> ans = subset(arr);
    cout << "Subsets:" << endl;
    printSubsets(ans);

    return 0;
}
