#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralprint(vector<vector<int>> matrix){
    int row=matrix.size();
    int column=matrix[0].size();
    vector<int> ans;
    int count=0;
    int total=row*column;

    int startingrow=0;
    int startingcol=0;
    int endrow=row-1;
    int endcol=column-1;

    while(count<total){
        for(int i=startingcol;count<total&&i<=endcol;i++){
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
        for(int i=startingrow;count<total&&i<=endrow;i++){
            ans.push_back(matrix[i][endcol]);
            count++;
        }
        endcol--;
        for(int i=endcol;count<total&&i>=startingcol;i--){
            ans.push_back(matrix[endrow][i]);
            count++;
        }
        endrow--;
        for(int i=endrow;count<total&&i>=startingrow;i--){
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;;
    }
    return ans;
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

    vector<int> m=spiralprint(arr);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
    }
    return 0;
}