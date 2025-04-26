#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void sort(int arr[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        while(arr[s]==0){
            s++;
        }
        while(arr[e]==1){
            e--;
        }
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
int main(){
    int arr[]={0,1,0,1,1,1,1,0,0,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    sort(arr,n);
    cout<<endl;
    printarray(arr,n);
    return 0;
}