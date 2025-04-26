#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

void Firstnonrepeating(string &s) {
    string ans = "";
    unordered_map<char, int> count;
    queue<char> q; // <-- Change queue<int> to queue<char>
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        count[ch]++;
        q.push(ch);
        while (!q.empty()) {
            if (count[q.front()] > 1) {
                q.pop();
            } else {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty()) {
            ans.push_back('#');
        }
    }
    cout << ans << endl; // <-- Add this line to output the result
    return;
}

int main() {
    string s = "aabcdeee";
    Firstnonrepeating(s);
    return 0;
}
