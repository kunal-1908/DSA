#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
void printarray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int duplicates(vector<int>& arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
}
int main(){
    vector<int> arr={1,1,2,4,5,6,7,8,9};
    printarray(arr);
    cout<<endl;
    int m=duplicates(arr);
    cout<<m<<endl;

    return 0;
}