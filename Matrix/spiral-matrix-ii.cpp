#include <iostream>
#include <vector>
using namespace std;

// generate a nxn matrix in spiral order from 1 to n*n elements
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n));
    int r1 = 0, c1 = 0, lr = n - 1, lc = n - 1; // Define boundaries
    int value = 1, total = n * n;

    while (value <= total) // after each complete round , go inward ,so
                           // r1++,lr--,c1++,lc--
    {
        // Move right
        for (int c = c1; c <= lc && value <= total; c++)
        {
            result[r1][c] = value;
            value++;
        }
        r1++;
        // Move down
        for (int r = r1; r <= lr && value <= total; r++)
        {
            result[r][lc] = value;
            value++;
        }
        lc--;
        // Move left
        for (int c = lc; c >= c1 && value <= total; c--)
        {
            result[lr][c] = value;
            value++;
        }
        lr--;

        // Move up
        for (int r = lr; r >= r1 && value <= total; r--)
        {
            result[r][c1] = value;
            value++;
        }
        c1++;
    }
    return result;
}

int main()
{
    vector<vector<int>> result = generateMatrix(3);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}