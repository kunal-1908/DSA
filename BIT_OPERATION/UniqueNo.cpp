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
int findunique(vector<int>& arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    vector<int> arr={2,4,5,6,7,8,8,7,6,5,4};
    printarray(arr);
    cout<<endl;
    int m=findunique(arr);
    cout<<"unique no. is: "<<m<<endl;
    return 0;
}