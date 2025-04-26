#include<iostream>
#include<vector>
using namespace std;
void LargestRowSum(vector<vector<int>> matrix){
    cout<<"Largest Row sum is:"<<endl;
    int max=INT16_MIN;
     vector<int> temp;
    for(int i=0;i<matrix.size();i++){
        int sum=0;
        for(int j=0;j<matrix[0].size();j++){
            sum=sum+matrix[i][j];
        }
        if(sum>max){
            max=sum;
        }
     }
     cout<<max<<endl;
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

    LargestRowSum(arr);
    return 0;
}