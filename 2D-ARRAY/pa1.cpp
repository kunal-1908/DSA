#include<iostream>
#include<vector>
using namespace std;
void change(vector<vector<int>>& matrix,int key){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==key){
                matrix[i][j]+=3;
                return;
            }
        }
    }
}

int main(){
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;
    int column;
    cout << "Enter the number of columns: ";
    cin >> column;

    vector<vector<int>> arr(row, vector<int>(column));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Enter the element at row " << i + 1 << " and column " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }

    cout << "\nThe 2D array is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    change(arr,3);
    cout << "\nAfter change The 2D array is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
