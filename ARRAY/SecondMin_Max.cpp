#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubblesort(int arr[],int n){
    int issorted=0;
    for(int i=0;i<n-1;i++){
        issorted=1;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                issorted=0;
            }
        }
        if(issorted)
        return;
    }
}
int secondlargest(int arr[],int n){
    int largest=INT8_MIN;
    int seclargest=INT8_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]<largest && arr[i]>seclargest){
            seclargest=arr[i];
        }
    }
    return seclargest;
}
int secondsmallest(int arr[],int n){
    int smallest=INT8_MAX;
    int secsmallest=INT8_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>smallest && arr[i]<secsmallest){
            secsmallest=arr[i];
        }
    }
    return secsmallest;
}
int main(){
    int arr[]={34,89,76,45,23,87,16,10,90,92};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    printarray(arr,n);
    cout<<endl;
    int m=secondlargest(arr,n);
    cout<<"2nd largest element in the array is:"<<m<<endl;
    int v=secondsmallest(arr,n);
    cout<<"2nd smallest element in the array is"<<v<<endl;
    return 0;
}