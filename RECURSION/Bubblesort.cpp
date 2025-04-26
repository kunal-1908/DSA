#include<iostream>
#include<vector>
using namespace std;
void printarray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void bubblesort(vector<int>& arr,int n){
    if(n==0||n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return bubblesort(arr,n-1);
}
int main(){
    vector<int> arr={2,9,1,3,90,30,20};
    int n=arr.size();
    printarray(arr);
    cout<<endl;
    bubblesort(arr,n);
    printarray(arr);
    return 0;
}