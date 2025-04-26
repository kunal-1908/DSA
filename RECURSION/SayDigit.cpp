#include<iostream>
using namespace std;
void solve(int n,string arr[]){
    if(n==0){
        return;
    }
    int digit=n%10;
    n=n/10;
    solve(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"enter the no."<<endl;
    cin>>n;

    solve(n,arr);
    return 0;
}