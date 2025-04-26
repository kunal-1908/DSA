#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int binarysearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
int main(){
    int arr[]={11,22,33,44,55,66,77,88,99,111};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    cout<<endl;
    if(binarysearch(arr,n,99) != -1){
        cout<<"the element is +nt."<<endl;
    }
    else{
        cout<<"the element is -nt."<<endl;
    }
    return 0;
}