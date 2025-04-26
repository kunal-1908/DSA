#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void movezeroes(int arr[],int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}
int main(){
    int arr[]={1,2,3,4,0,0,0,9,8,6,0,0,3,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    cout<<endl;
    movezeroes(arr,n);
    printarray(arr,n);
}