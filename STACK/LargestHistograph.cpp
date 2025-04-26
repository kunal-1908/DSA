#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextsmallerelement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    int i=n-1;
    while(i>=0){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
        i--;
    }
    return ans;
}
vector<int> prevsmallerelement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    int i=0;
    while(i<n){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
        i++;
    }
    return ans;
}
int findmaxarea(vector<int> arr){
    int n=arr.size();

    vector<int> next(n);
    next=nextsmallerelement(arr,n);

    vector<int> prev(n);
    prev=prevsmallerelement(arr,n);

    int area=INT32_MIN;
    for(int i=0;i<n;i++){
        int length=arr[i];

        if(next[i]==-1){
            next[i]=n;
        }

        int breadth=next[i]-prev[i]-1;
        int newarea=length*breadth;
        area=max(area,newarea);
    }
    return area;
}
int main(){
    vector<int> arr={2,4,5,6,1};

    int ans=findmaxarea(arr);
    cout<<"largest histogram area:"<<ans<<endl;
    return 0;
}