#include<iostream>
using namespace std;
int root(int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }
        else if(square<n){
            ans=mid;
            s=mid+1;
        }
        else
        e=mid-1;
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter a number:-"<<endl;
    cin>>n;

    int m=root(n);
    cout<<"the root is:-"<<m<<endl;
}