#include<iostream>
using namespace std;
int solve(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=solve(n-2)+solve(n-1);
    return ans;
}
int main(){
    int n;
    cout<<"enter the no of steps:"<<endl;
    cin>>n;
    cout<<endl;
    int ans=solve(n);
    cout<<ans<<endl;
    return 0;
}