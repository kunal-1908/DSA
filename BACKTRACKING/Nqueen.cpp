#include <bits/stdc++.h>
using namespace std;

void addsoln(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, 
           unordered_map<int, bool> &leftRow, unordered_map<int, bool> &upperDiag, unordered_map<int, bool> &lowerDiag) {
    if (col == n) {
        addsoln(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (!leftRow[row] && !upperDiag[row - col] && !lowerDiag[row + col]) {
            board[row][col] = 1;
            leftRow[row] = true;
            upperDiag[row - col] = true;
            lowerDiag[row + col] = true;

            solve(col + 1, ans, board, n, leftRow, upperDiag, lowerDiag);

            board[row][col] = 0;  // Backtrack
            leftRow[row] = false;
            upperDiag[row - col] = false;
            lowerDiag[row + col] = false;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> ans;
    if (n <= 0) return ans;

    vector<vector<int>> board(n, vector<int>(n, 0));
    unordered_map<int, bool> leftRow, upperDiag, lowerDiag; // Hash maps for row and diagonal checks

    solve(0, ans, board, n, leftRow, upperDiag, lowerDiag);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> result = nQueens(n);
    for (auto &solution : result) {
        for (int cell : solution) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
#include <bits/stdc++.h>
bool issafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true;
}
void addsoln(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;  // Fixed declaration to store a single solution in a 1D vector

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);  // Push the solution into the list of answers
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if (col == n) {
        addsoln(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (issafe(row, col, board, n)) {
            board[row][col] = 1;

            solve(col + 1, ans, board, n);

            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n) {
    vector<vector<int>> ans;
    if (n <= 0) {
        return ans;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, ans, board, n);
    return ans;
}

*/