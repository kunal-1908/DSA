#include<iostream>
#include<queue>
using namespace std;
int main(){
    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);
    d.push_front(60);
    d.push_front(70);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();
    d.pop_front();

    if(d.empty()){
        cout<<"stack underflow."<<endl;
    }
    else{
        cout<<"stack overflow."<<endl;
    }
    return 0;
}