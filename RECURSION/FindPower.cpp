#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0 || a==1){
        return 1;
    }
    int ans=power(a,b/2);
    if(b%2==0){
        return ans*ans;
    } 
    else{
        return ans*ans*a;
    }
}
int main(){
    int a;
    cout<<"enter the value of a: ";
    cin>>a;
    int b;
    cout<<"enter the value of b: ";
    cin>>b;
    int ans=power(a,b);
    cout<<"the value is: "<<ans<<endl;
}