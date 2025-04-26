#include<iostream>
#include<math.h>
using namespace std;
int countbit(int n){
    int count=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
int main(){
    int n;
    cout<<"enter the number: "<<endl;
    cin>>n;
    cout<<endl;
    int m=countbit(n);
    cout<<"total no of 1 bit: "<<m<<endl;

    return 0;
}