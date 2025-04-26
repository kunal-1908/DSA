#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> complement(int n){
    vector<int> ans;
    if(n==0){
        ans.push_back(1);
        return ans;
    }
    while(n!=0){
        if(n&1==1){
            ans.push_back(0);
        }
        else{
            ans.push_back(1);
        }
        n=n>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cout<<"enter the number: "<<endl;
    cin>>n;

    vector<int> m=complement(n);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
    }

    return 0;
}