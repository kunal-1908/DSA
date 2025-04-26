#include<iostream>
using namespace std;
void solve(int src,int dest){
    cout<<src<<" "<<dest<<endl;
    if(src==dest){
        cout<<"poonch gye"<<endl;
        return;
    }
    src++;
    solve(src,dest);
}
int main(){
    int dest=10;
    int src=1;
    cout<<endl;

    solve(src,dest);
    return 0;
}