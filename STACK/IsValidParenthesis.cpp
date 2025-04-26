#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isvalidparenthesis(string str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else {
            if(!s.empty()) {
                char top = s.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string str = "{[()]}";
    cout << str << endl;

    if(isvalidparenthesis(str)) {
        cout << "Valid parenthesis." << endl;
    } else {
        cout << "Invalid parenthesis." << endl;
    }
    
    return 0;
}
