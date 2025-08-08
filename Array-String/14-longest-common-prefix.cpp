#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    /******Optimized apprach  *******/
    // int n = strs.size();
    //     for (int i = 0; i < strs[0].size(); ++i) {
    //         for (int j = 1; j < n; ++j) {
    //             if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
    //                 return strs[0].substr(0, i);
    //             }
    //         }
    //     }
    //     return strs[0];

    // Brute force approach
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        for (string str : strs)
        { // createing uneccesory copy of string in
          // each iteration
            if (str.length() <= i || str[i] != ch)
            {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}