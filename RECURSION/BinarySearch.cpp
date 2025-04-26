#include<iostream>
#include<vector>
using namespace std;

bool binarysearch(vector<int>& arr, int s, int e, int key) {
    if(s > e) {
        return false;
    }
    int mid = s + (e - s) / 2;
    if(arr[mid] == key) {
        return true;
    }
    else if(arr[mid] > key) {
        return binarysearch(arr, s, mid - 1, key);
    }
    else {
        return binarysearch(arr, mid + 1, e, key);
    }
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 11, 22, 44, 55, 77, 99, 100};
    int n = arr.size();

    if(binarysearch(arr, 0, n-1, 99)) {
        cout << "present." << endl;
    } else {
        cout << "absent." << endl;
    }

    return 0;
}
