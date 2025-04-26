#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>> arr,int a,int b){
    if(arr[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}
int findcelebrity(vector<vector<int>> arr,int n){
    stack<int> s;

    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(arr,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans=s.top();
    s.pop();

    //verify the answer that he is celebrity or not.
    int zerocount=0;
    for(int i=0;i<n;i++){
        if(arr[ans][i]==0){
            zerocount++;
        }
    }
    //all zeroes
    if(zerocount!=n){
        return -1;
    }

    int onecount=0;
    for(int i=0;i<n;i++){
        if(arr[i][ans]==1){
            onecount++;
        }
    }
    //all ones
    if(onecount!=n-1){
        return -1;
    }

    return ans;
}
int main(){
    vector<vector<int>> arr={
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int n=arr.size();

   int ans = findcelebrity(arr, n);
    if (ans == -1) {
        cout << "There is no celebrity." << endl;
    } else {
        cout << "Celebrity is person having row no.: " << ans << endl;
    }
    return 0;
}