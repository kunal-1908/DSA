#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& arr, int n) {
    if(n==0){
        return 0;
    }
    int remainingpart=solve(arr,n-1);
    int sum=arr[n-1]+remainingpart;
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    cout << solve(arr, n) << endl;
    return 0;
}
