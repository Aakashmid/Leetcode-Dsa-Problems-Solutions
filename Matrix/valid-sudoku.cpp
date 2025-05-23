#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<unordered_map<char, int>> rows(9);
    vector<unordered_map<char, int>> cols(9);
    vector<vector<unordered_map<char, int>>> squares(3, vector<unordered_map<char, int>>(3)); // Initialize 3x3 grid of unordered maps

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (board[r][c] == '.')
            {
                continue;
            }
            else if (rows[r].count(board[r][c]) ||
                     cols[c].count(board[r][c]) ||
                     squares[r / 3][c / 3].count(board[r][c])) // Corrected access to squares
            {
                return false;
            }
            else
            {
                rows[r][board[r][c]] = 1;
                cols[c][board[r][c]] = 1;
                squares[r / 3][c / 3][board[r][c]] = 1; // Corrected access to squares
            }
        }
    }
    return true;
}

int main()
{
    return 0;
}