#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> findnextelement(vector<int> arr, int n){
    vector<int> ans;
    stack<int> s;
    s.push(-1);

    int i = n - 1;
    while(i >= 0){
        int curr = arr[i];
        while(s.top() != -1 && s.top() >= curr){ // Fix the condition here
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
        i--; // Add the decrement of i
    }
    reverse(ans.begin(), ans.end()); // Reverse the answer to match the original order
    return ans;
}

void print(vector<int> ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    vector<int> ans = findnextelement(arr, n);
    print(ans);
    
    return 0;
}
