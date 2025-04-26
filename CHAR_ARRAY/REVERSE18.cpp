#include<iostream>
#include<string>
using namespace std;

bool isvalid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

char toLowercase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

bool checkpalindrome(string& s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool ispalindrome(string& s) {
    string temp;
    for (int j = 0; j < s.length(); j++) {
        if (isvalid(s[j])) {
            temp.push_back(toLowercase(s[j]));
        }
    }
    return checkpalindrome(temp);
}

int main() {
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);

    if (ispalindrome(s)) {
        cout << "Palindrome." << endl;
    } else {
        cout << "Not palindrome." << endl;
    }

    return 0;
}
