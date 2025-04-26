#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void print(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> findans(vector<int> arr, int size, int k) {
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < k; i++) {
        if(arr[i] < 0) {
            q.push(i);
        }
    }

    // store ans for 1st window
    if(q.size() > 0) {
        ans.push_back(arr[q.front()]);
    } else {
        ans.push_back(0);
    }

    // now process the remaining part
    for(int i = k; i < size; i++) {
        if(!q.empty() && (i - q.front()) >= k) {
            q.pop();
        }
        if(arr[i] < 0) {
            q.push(i);
        }
        if(!q.empty()) {
            ans.push_back(arr[q.front()]);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1, 8, -2, -4, -6, 9, 20, -7};
    int n = arr.size();
    int windowsize = 2;

    vector<int> ans = findans(arr, n, windowsize);
    print(ans);  // printing the result array instead of the original array

    return 0;
}
