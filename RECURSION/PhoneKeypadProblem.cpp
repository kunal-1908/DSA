#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printstring(const vector<string>& str) {
    for(int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}
void solve(const string& digit, string output, int index, vector<string>& ans, const vector<string>& mapping) {
    if(index >= digit.length()) {
        ans.push_back(output);
        return;
    }
    int number = digit[index] - '0';
    string value = mapping[number];
    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        // Backtracking
        output.pop_back();
    }
}
vector<string> phonekeypad(const string& digit) {
    vector<string> ans;
    string output = "";
    int index = 0;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqr", "stuv", "wxyz"};
    solve(digit, output, index, ans, mapping);
    return ans;
}
int main() {
    string digit = "23";
    printstring({digit});
    vector<string> ans = phonekeypad(digit);
    printstring(ans);
    return 0;
}
