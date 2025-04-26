#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int> arr,int n,int key){
   if(n==0){
    return false;
   }
   if(arr[n-1]==key){
    return true;
   }
   bool remainingpart=search(arr,n-1,key);
   return remainingpart;
}
int main() {
    vector<int> arr = {3,7,90,32,1,67,84};
    int n = arr.size();
    if(search(arr,n,99)){
        cout<<"present."<<endl;
    }
    else
    cout<<"absent."<<endl;
    return 0;
}