#include<iostream>
#include<vector>
#include<string>
using namespace std;
void print(const vector<vector<int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}
void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);  
        solve(nums, index + 1, ans);
        //backtrack
        swap(nums[index], nums[j]);
    }
}
vector<vector<int>> permutation(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Permutations:" << endl;
    
    vector<vector<int>> ans = permutation(nums);
    print(ans);

    return 0;
}
