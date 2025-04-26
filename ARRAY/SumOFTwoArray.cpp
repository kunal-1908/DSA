#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> print(vector<int>&array){
    int n=array.size();
    for(int k=0;k<n;k++){
        cout<<array[k]<<" ";
    }
    return array;
}
vector<int> suumm(vector<int> &array1,vector<int> &array2,int n,int m){
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry=0;

    while(i>=0 && j>=0){
        int sum=array1[i]+array2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
        i--;
    }
    while(i>=0){
        int sum=array1[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0){
        int sum=array2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> array1={9,4,0,2,9,9,9,9,9};
    int n=array1.size();
    vector<int> array2={1,6,9,4,9,4,7};
    int m=array2.size();

    vector<int> result=suumm(array1,array2,n,m);
    print(result);
    return 0;
}