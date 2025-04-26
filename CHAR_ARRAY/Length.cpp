#include<iostream>
using namespace std;
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

    int m=getlength(name);
    cout<<"length:"<<m<<endl;
    return 0;
}