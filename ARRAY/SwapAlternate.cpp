#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void reverseAlt(int arr[],int n){
    for(int i=0;i<n;i=i+2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int arr[]={10,20,30,40,50,60,70,80};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    cout<<endl;
    reverseAlt(arr,n);
    printarray(arr,n);
}