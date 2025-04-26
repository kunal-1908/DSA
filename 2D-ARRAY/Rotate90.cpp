#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Function to rotate the 2D array by 90 degrees clockwise
void rotate90Clockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();  // assuming it's an n x n matrix
    
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to print the 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input the matrix
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    // Rotate the matrix by 90 degrees clockwise
    rotate90Clockwise(matrix);

    cout << "Matrix after 90 degree rotation:\n";
    printMatrix(matrix);

    return 0;
}
