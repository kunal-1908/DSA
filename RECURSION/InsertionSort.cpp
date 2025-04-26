#include<iostream>
#include<vector>
using namespace std;

void printarray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(vector<int>& arr,int n){
    if(n==0||n==1){
        return;
    }
    
}
int main() {
    vector<int> arr = {2, 9, 1, 3, 90, 30, 20};
    int n = arr.size();

    cout << "Original array: ";
    printarray(arr);

    InsertionSort(arr,n-1);

    cout << "Sorted array: ";
    printarray(arr);

    return 0;
}
