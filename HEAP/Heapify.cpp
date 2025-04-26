#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int leftchild=2*i;
    int rightchild=2*i+1;

    if(leftchild<n && arr[leftchild]>arr[largest]){
        largest=leftchild;
    }
    if(rightchild<n && arr[rightchild]>arr[largest]){
        largest=rightchild;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
int main(){
    int arr[]={-1,90,80,65,98,87,23,45,67,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"array before heapify"<<endl;
    printarray(arr,n);
    cout<<"array after heapify"<<endl;
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    printarray(arr,n);
    return 0;
}