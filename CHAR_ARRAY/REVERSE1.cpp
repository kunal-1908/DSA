#include<iostream>
using namespace std;
void reverse(string& s, int n) {
    int a = 0;
    int e = n - 1;
    while (a < e) {
        swap(s[a], s[e]);
        a++;  
        e--;
    }
}
int getlength(string s){
    int len=0;
    for(int i=0; s[i]!='\0'; i++){
        len++;
    }
    return len;
}
int main(){
    string s;
    cout<<"enter the string:"<<endl;
    getline(cin, s);
    
    int m=getlength(s);
    reverse(s,m);
    cout<<s<<endl;
    return 0;
}