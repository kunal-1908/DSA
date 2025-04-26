#include<iostream>
using namespace std;

void reverse(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
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
    reverse(name,m);
    cout<<"your name is:"<<name<<endl;
    return 0;
}