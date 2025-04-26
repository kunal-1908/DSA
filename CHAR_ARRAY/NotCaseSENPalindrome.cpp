#include<iostream>
using namespace std;
void lowercase(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] - 'A' + 'a';
        }
    }
}
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
    cout<<"enter the char array:"<<endl;
    cin>>name;
    cout<<"array  is:"<<name<<endl;

    int m=getlength(name);
    lowercase(name);
    cout<<"name is:"<<name<<endl;
    if(palindrome(name,m)){
        cout<<"palindrome."<<endl;
    }
    else{
        cout<<"not palindrome."<<endl;
    }
    return 0;
}