#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverse(string &s){
    int n = s.length();
    int i = 0;
    while(i < n){
        int start = i;
        while(i < n && s[i] != ' '){
            i++;
        }
        int end = i - 1;
        while(start < end){
            swap(s[start++], s[end--]);
        }
        i++;
    }
}

int main(){
    string s;
    cout << "enter the string:" << endl;
    getline(cin, s);

    reverse(s);
    cout << "the reverse string is:" << s << endl;

    return 0;
}