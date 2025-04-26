#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int firstoccurance(int arr[],int n,int key){
    int ans=-1;
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastoccurance(int arr[],int n,int key){
    int ans=-1;
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[]={2,3,4,4,4,4,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    printarray(arr,n);
    cout<<endl;
    int m=firstoccurance(arr,n,4);
    int v=lastoccurance(arr,n,4);
    cout<<"the first occurance is at index no. "<<m<<endl;
    cout<<"the last occurance is at index no. "<<v<<endl;
    
    return 0;
}