#include<iostream>
#include<stack>
#include<string>
using namespace std;
int findmincost(string str){
    if(str.length()%2==1){
        return -1;
    }
    stack<char> s;
    for(int i;i<str.length();i++){
        char ch=str[i];

        if(ch=='{'){
            s.push(ch);
        }
        else{
            if(ch=='}'){
                if(!s.empty()&& s.top()=='{'){
                    s.pop();
                }
                else{
                    s.push(ch);
                }
            }
        }
    }
    int a=0;
    int b=0;
    while(!s.empty()){
        if(s.top()=='{'){
            a++;
        }
        else b++;
    }
    int ans=(a+1)/2+(b+1)/2;
    return ans;
}
int main(){
    string str="}}}{{{";

    int ans=findmincost(str);
    cout<<"minimum cost is:"<<ans<<endl;
    return 0;
}