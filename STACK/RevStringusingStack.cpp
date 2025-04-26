#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    string str = "babbar";
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << "After reversing, the string is: " << ans << endl;

    return 0;
}
