#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isprime(int n){
    for(int j=2;j<n;j++){
        if(n%j==0){
            return false;
        }
    }
    return true;
}
void printarray(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;
    vector<int> ans;

    for(int i=2;i<n;i++){
        if(isprime(i)){
            ans.push_back(i);
        }
    }

    printarray(ans);
    return 0;
}