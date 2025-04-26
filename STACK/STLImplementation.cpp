#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    if(s.empty()){
        cout<<"stack is empty."<<endl;
    }
    else{
        cout<<"stack is not empty."<<endl;
    }
    return 0;
}