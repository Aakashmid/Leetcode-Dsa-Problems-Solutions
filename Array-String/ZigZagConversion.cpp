#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        /************Approach 1 *************/
        // if(numRows==1 || s.length()<=numRows){
        //     return s;
        // }

        // vector<vector<char>> rows(numRows);
        // string result="";
        // int row_i=0,d=1; // direction of movement , if 1 then down and if -1
        // up for(char ch:s){
        //     rows[row_i].push_back(ch);
        //     if(row_i== numRows-1){
        //         d=-1;
        //     }
        //     else if(row_i==0){
        //         d=1;
        //     }
        //     row_i+=d;
        // }
        // for(int i=0;i<numRows;i++){
        //     for(int j=0;j<rows[i].size();j++){
        //         result+=rows[i][j];
        //     }
        // }
        // return result;

        /************Approach 2 *************/
        // Initialize empty result string
        string result = "";
        int len = s.length();

        // If number of rows is 1 or string length is less than numRows
        // no need for zigzag conversion, return original string
        if (numRows == 1 || len <= numRows)
        {
            return s;
        }

        // Iterate through each row
        for (int r = 0; r < numRows; r++)
        {
            // Calculate the increment between two characters in same  row
            // Formula: 2 * (numRows - 1)
            int increment = 2 * (numRows - 1);

            // For each row, find characters that belong to this row
            for (int j = r; j < len; j += increment)
            {
                // Add the character in vertical line
                result += s[j];

                // For middle rows (not first or last row)
                // Add the character in diagonal line
                // Formula for diagonal character: j + increment - 2 * current_row
                if (r > 0 && r < numRows - 1 && j + increment - 2 * r < len)
                {
                    result += s[j + increment - 2 * r];
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    cout << sol.convert(s, numRows) << endl;
    return 0;
}