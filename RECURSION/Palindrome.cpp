#include<iostream>
#include<string>
using namespace std;
void print(string &s){
    for(int i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
}
bool ispalindrome(string s,int a,int e){
    if(a>e){
        return true;
    }
    if(s[a]!=s[e]){
        return false;
    }
    return ispalindrome(s,a+1,e-1);
}
int main(){
    string s="babbar";
    int n=s.size();
    print(s);
    cout<<endl;
    if(ispalindrome(s,0,n-1)){
        cout<<"true."<<endl;
    }
    else{
        cout<<"false."<<endl;
    }
    return 0;
}