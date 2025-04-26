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
int findlargestarea(vector<vector<int>> arr){
    int area=findmaxarea(arr[0]);

    for(int i=1;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            //update the row
            if(arr[i][j]!=0){
                arr[i][j]=arr[i][j]+arr[i-1][j];
            }
            else{
                arr[i][j]=0;
            }
            //entire row is updated
            area=max(area,findmaxarea(arr[i]));
        }
    }
    return area;
}
int main(){
    vector<vector<int>> arr={
        {1,0,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,1}
    };

    int n=arr.size();
    int m=arr[0].size();

    int ans=findlargestarea(arr);
    if(ans!=-1){
        cout<<"the area of largest rectangle is"<<ans<<endl;
    }
    return 0;
}