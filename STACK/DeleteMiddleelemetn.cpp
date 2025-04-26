#include<iostream>
#include<stack>
using namespace std;
void deletemidelement(stack<int> &s,int count,int size){
    if(count==size/2){
        s.pop();
        return;
    }

    int num=s.top();
    s.pop();
    count++;

    deletemidelement(s,count,size);

    s.push(num);
}
int main(){

    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    int count=0;
    int n = s.size();

    deletemidelement(s,count,n);
    cout<<"after deletion."<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}