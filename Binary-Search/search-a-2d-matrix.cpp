#include<iostream>
#include<vector>
using namespace std;
// approach - first find the row in which target can be found and after that run binary search on that row's elements


// time complexity - O(log(m)+log(n)) , memory complexity - O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l_row = 0, r_row = matrix.size() - 1;
    int cols = matrix[0].size();

    while (l_row <= r_row)
    {
        
        int mid_row = (l_row + r_row) / 2;

        // target element is in  current row
        if (target <= matrix[mid_row][cols - 1] &&
            target >= matrix[mid_row][0])
        {
            // ---

            int l = 0, h = cols - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (matrix[mid_row][mid] == target)
                {
                    return true;
                }
                else if (matrix[mid_row][mid] > target)
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return false;
            // ---
        }
        else if (target < matrix[mid_row][0])
        {
            r_row = mid_row - 1;
        }
        else
        {
            l_row = mid_row + 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {60, 61, 62, 63}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl; // Output: true
    return 0;
}