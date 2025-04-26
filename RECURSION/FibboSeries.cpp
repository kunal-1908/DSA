#include<iostream>
using namespace std;
int solve(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int ans = solve(n - 1) + solve(n - 2);
    return ans;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "Fibonacci numbers up to n:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << solve(i) << " ";
    }
    cout << endl;
    return 0;
}
