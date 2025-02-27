#include <iostream>
#include <vector>
using namespace std;


// Given an m x n matrix, return all elements of the matrix in spiral order. 
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty())
        return result; // Edge case: empty matrix

    int m = matrix.size(), n = matrix[0].size(); // m = rows, n = columns
    int r1 = 0, c1 = 0, lr = m - 1, lc = n - 1;  // Define boundaries
    int count = 0, total = m * n;

    while (count < total) // after each complete round , go inward ,so r1++,lr--,c1++,lc--
    {
        // Move right
        for (int c = c1; c <= lc && count < total; c++)
        {
            result.push_back(matrix[r1][c]);
            count++;
        }
        r1++;
        // Move down
        for (int r = r1; r <= lr && count < total; r++)
        {
            result.push_back(matrix[r][lc]);
            count++;
        }
        lc--;
        // Move left
        for (int c = lc; c >= c1 && count < total; c--)
        {
            result.push_back(matrix[lr][c]);
            count++;
        }
        lr--;

        // Move up
        for (int r = lr; r >= r1 && count < total; r--)
        {
            result.push_back(matrix[r][c1]);
            count++;
        }
        c1++;
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}