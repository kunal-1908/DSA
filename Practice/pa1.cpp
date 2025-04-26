#include<iostream>
#include<vector>
using namespace std;
char lowercase(char ch){
    if(ch>='a'&& ch<='z'){
        return ch;
    }
    else{
        char m=ch-'A'+'a';
        return m;
    }
}
bool validpalindrome(string s,int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(lowercase(s[i])!=lowercase(s[j])){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
int main(){
    string s={"abcdeEDCBA"};
    int n=10;

    if(validpalindrome(s,n)){
        cout<<"true."<<endl;
    }
    else{
        cout<<"false."<<endl;
    }
    return 0;
}