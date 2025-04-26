#include<iostream>
#include<queue>
using namespace std;
class stacktoqueue{
    queue<int> q;

    public:
    void push(int x){
        int n=q.size();
        q.push(x);

        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout<<"stack is empty."<<endl;
            return;
        }
        else{
            q.pop();
        }
    }

    int topelement(){
        if(q.empty()){
            cout<<"stack is empty."<<endl;
            return -1;
        }
        else{
            return q.front();
        }
    }

    void print(){
        if(q.empty()){
            cout<<"stack is empty."<<endl;
            return;
        }
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
};
int main(){
    stacktoqueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.print();
    return 0;
}