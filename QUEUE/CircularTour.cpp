#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> petrol,vector<int> distance){
    int n=petrol.size();
    int balance=0;
    int deficit=0;
    int start=0;

    for(int i=0;i<n;i++){
        balance=balance+petrol[i]-distance[i];
        if(balance<0){
            start=i+1;
            deficit=deficit+balance;
            balance=0;
        }
    }
    if(balance+deficit>=0){
        return start;
    }
    return -1;
}
int main(){
    vector<int> petrol={6,7,4,10,6,5};
    vector<int> distance={5,6,7,8,6,4};

    int startingpoint=solve(petrol,distance);
    if(startingpoint!=-1){
        cout<<"the starting point is:"<<startingpoint<<endl;
    }
    else{
        cout<<"not possible."<<endl;
    }
    return 0;
}