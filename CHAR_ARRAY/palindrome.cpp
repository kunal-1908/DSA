#include<iostream>
using namespace std;

bool palindrome(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        if(name[s]!=name[e]){
            return false;
        }
       else{
            s++;
            e--;
        }
    }
    return true;
}

int getlength(char name[]){
    int len=0;
    for(int i=0; name[i]!='\0'; i++){
        len++;
    }
    return len;
}

int main(){
    char name[20];
    cout<<"enter the name:"<<endl;
    cin>>name;
    cout<<"name is:"<<name<<endl;

    int m=getlength(name);
    if(palindrome(name,m)){
        cout<<"palindrome."<<endl;
    }
    else{
        cout<<"not palindrome."<<endl;
    }
    return 0;
}