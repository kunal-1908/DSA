#include<iostream>
using namespace std;

int root(int n) {
    int s = 0;
    int e = n;  // Initialize `e` as `n` not `n-1`
    int mid = s + (e - s) / 2;
    int ans = -1;
    
    while (s <= e) {
        long long square = mid * mid;
        if (square == n) {
            return mid;  // If we find an exact square root
        } else if (square < n) {
            ans = mid;  // Store the closest integer part of the root
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    
    return ans;  // Return the integer part of the square root
}

double perfectroot(int n, int tempsol, int precision) {
    double ans = tempsol;
    double factor = 1;
    
    // For each level of precision, we reduce the factor by 10
    for (int i = 0; i < precision; i++) {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor) {
            ans = j;
        }
    }
    
    return ans;  // Return a more precise answer as a double
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int intRoot = root(n);  // Get integer part of the square root
    double preciseRoot = perfectroot(n, intRoot, 5);  // Get the precise root with 5 decimal places

    cout << "The square root is: " << preciseRoot << endl;

    return 0;
}
