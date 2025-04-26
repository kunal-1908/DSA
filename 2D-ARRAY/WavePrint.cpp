#include<iostream>
#include<vector>
using namespace std;
vector<int> wavePrint(vector<vector<int>> matrix){
    int row=matrix.size();
    int column=matrix[0].size();
    vector<int> temp;
    for(int i=0;i<column;i++){
        if(i&1){
            //bottom to up.
            for(int j=row-1;j>=0;j--){
                temp.push_back(matrix[j][i]);
            }
        }
        else{
            //top to bottom
            for(int j=0;j<row;j++){
                temp.push_back(matrix[j][i]);
            }
        }
    }
    return temp;
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
    cout<<endl;

    vector<int> m=wavePrint(arr);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
    }
    return 0;
}