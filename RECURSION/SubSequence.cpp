#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printsubsequence(const vector<vector<string>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "} ";
    }
    cout << endl;
}

void printstring(const vector<string>& str) {
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

void solve(string str, string output, int index, vector<vector<string>>& ans) {
    if (index >= str.size()) {
        if (!output.empty()) {
            vector<string> singleOutput = {output};
            ans.push_back(singleOutput);
        }
        return;
    }

    // Exclude the current element
    solve(str, output, index + 1, ans);

    // Include the current element
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<vector<string>> subsequence(string& str) {
    vector<vector<string>> ans;
    string output;
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
int main() {
    string str = "abc   ";

    cout << "Original string: " << str << endl;

    vector<vector<string>> ans = subsequence(str);

    cout << "Subsequences: ";
    printsubsequence(ans);

    return 0;
}
