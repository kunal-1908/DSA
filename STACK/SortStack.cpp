#include<iostream>
#include<stack>
using namespace std;
void sortedinsert(stack<int> &s,int num){
    if(s.empty() || (!s.empty() && s.top()>num)){
        s.push(num);
        return;
    }

    int element=s.top();
    s.pop();

    sortedinsert(s,num);
    s.push(element);
}
void sortstack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num=s.top();
    s.pop();

    sortstack(s);

    sortedinsert(s,num);
}
int main(){
    stack<int> s;
    s.push(90);
    s.push(70);
    s.push(80);
    s.push(10);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(30);

    sortstack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}