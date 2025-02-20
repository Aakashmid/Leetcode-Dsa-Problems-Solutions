#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Checks whether a given Sudoku board is valid.
 * A valid board follows these rules:
 * - Each row contains unique numbers (1-9) without repetition.
 * - Each column contains unique numbers (1-9) without repetition.
 * - Each 3x3 subgrid contains unique numbers (1-9) without repetition.
 *
 * The function ignores empty cells represented by '.'
 */
bool isValidSudoku(vector<vector<char>> &board) {
    vector<unordered_set<char>> rows(9), cols(9);
    vector<vector<unordered_set<char>>> squares(3, vector<unordered_set<char>>(3));

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char val = board[r][c];
            if (val == '.') continue;

            // Check if the value is already present in the row, column, or 3x3 grid
            if (rows[r].count(val) || cols[c].count(val) || squares[r / 3][c / 3].count(val)) {
                return false;
            }

            // Insert the value into respective row, column, and 3x3 grid sets
            rows[r].insert(val);
            cols[c].insert(val);
            squares[r / 3][c / 3].insert(val);
        }
    }
    return true;
}

int main()
{
    return 0;
}