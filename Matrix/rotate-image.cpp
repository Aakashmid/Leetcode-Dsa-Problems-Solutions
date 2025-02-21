#include<iostream>
#include<vector>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> result(n,vector<int>(n));
    for(int r=0;r<n;r++){
        int col=n-r-1;
        for(int j=0;j<n;j++){
            result[j][col]=matrix[r][j];
        }
    }
    matrix=result;
}


int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}