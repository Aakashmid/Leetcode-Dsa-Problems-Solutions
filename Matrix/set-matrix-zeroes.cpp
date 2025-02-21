#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    unordered_map<int, bool>
        z_rows; // for tracking which row is completely zero
    unordered_map<int, bool>
        z_cols; // for tracking which column is completely zero
    vector<vector<int>> result(m, vector<int>(n));
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int temp_val = matrix[r][c];
            if (temp_val == 0)
            { // checking  if current index value is zero
                if (!z_rows.count(r))
                { // putting 0   in row r
                    for (int j = 0; j < n; j++)
                    {
                        result[r][j] = 0;
                    }
                    z_rows[r] = true; // updating that this row is completely zero
                }
                if (!z_cols.count(c))
                { // putting 0   in column c
                    for (int j = 0; j < m; j++)
                    {
                        result[j][c] = 0;
                    }
                    z_cols[c] = true; // updating that this column is completely zero
                }
            }
        }
    }

    // putting value to those postions which are not in z_rows and z_cols
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (!z_rows[r] && !z_cols[c])
            {
                result[r][c] = matrix[r][c];
            }
        }
    }
    matrix = result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}