#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void printarray(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printstring(vector<string> str) {
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& arr) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& arr, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 directions: down, up, right, left
    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, arr)) {
        path.push_back('D');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, arr)) {
        path.push_back('U');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, arr)) {
        path.push_back('R');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, arr)) {
        path.push_back('L');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> RatinMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(arr, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = arr.size();
    printarray(arr);
    
    vector<string> ans = RatinMaze(arr, n);
    printstring(ans);

    return 0;
}
