#include<iostream>
using namespace std;
void preinpost(int n){
    if(n==0){
        return;
    }
    cout<<"pre "<<n<<endl;
    preinpost(n-1);
    cout<<"in "<<n<<endl;
    preinpost(n-1);
    cout<<"post "<<n<<endl;
    return;
}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;
    preinpost(n);
    return 0;
}