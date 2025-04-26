#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void rotatearray(int arr[],int n,int k){
    int temp[n]={0};
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    cout<<endl;
    rotatearray(arr,n,4);
    printarray(arr,n);
    return 0;
}