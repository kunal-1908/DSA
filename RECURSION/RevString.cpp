#include<iostream>
#include<string>
using namespace std;
void print(string &s){
    for(int i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
}
void revstring(string &s,int a,int e){
    if(a>=e){
        return;
    }
    swap(s[a],s[e]);
    return revstring(s,a+1,e-1);
}
int main(){
    string s="babbar is the";
    int n=s.size();
    print(s);
    cout<<endl;

    revstring(s,0,n-1);
    print(s);
    return 0;
}