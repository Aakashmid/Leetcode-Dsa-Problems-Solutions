#include <iostream>
#include <vector>
using namespace std;


// get the number of alive neighbours of a cell
int aliveNeighbours(int r, int c, int m, int n,
                    vector<vector<int>> &board)
{
    int nei = 0;
    for (int i = r - 1; i < r + 2; i++)
    {
        for (int j = c - 1; j < c + 2; j++)
        {
            if ((i == m || j == n) || (i == r && j == c) ||
                (i < 0 or j < 0))
            {
                continue;
            }
            else if (board[i][j] == 1 || board[i][j] == 3)
            {
                nei++;
            }
        }
    }
    return nei;
}

// update the board according to the rules of the game of life

/*
original | new | state
0  | 0 | 0
1  | 0 | 1
0  | 1 | 2
1  | 1 | 3

*/
void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size(), n = board[0].size();
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int nei = aliveNeighbours(
                r, c, m, n, board); // get numbers of alive neighbours
            if (board[r][c] && (nei == 2 || nei == 3))
            {
                board[r][c] = 3;
            }
            else if (nei == 3)
            {
                board[r][c] = 2;
            }
        }
    }
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] == 2 || board[r][c] == 3)
            {
                board[r][c] = 1;
            }
            else if (board[r][c] == 1)
            {
                board[r][c] = 0;
            }
        }
    }
}

int main()
{
    return 0;
}