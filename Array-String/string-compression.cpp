#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void append_char(string group, vector<char> &s)
    {
        if (group.length() >= 10)
        {
            int n = group.length();
            s.push_back(group[0]);
            string numStr = to_string(group.length());
            for (char ch : numStr)
            {
                s.push_back(ch);
            }
        }
        else
        {
            if (group.length() == 1)
            {
                s.push_back(group[0]);
            }
            else
            {

                s.push_back(group[0]);
                s.push_back('0' + group.length());
            }
        }
    }

    int compress(vector<char> &chars)
    {
        /******* Approach 1 **********/
        // vector<char> s;
        // string group = "";
        // for (char ch:char) {

        //     if (group.length() >= 1) {
        //         if (group[0] == ch) {
        //             group += ch;
        //         } else {
        //             append_char(group,s);
        //             group = "";
        //             group += ch;
        //         }
        //     } else {
        //         group += ch;
        //     }
        // }

        // append_char(group,s);

        // chars = s;
        // cout << chars.size();
        // return chars.size();

        /******* Approach 2 **********/
        int i = 0;
        for (int j = 1, count = 1; j <= chars.size(); j++, count++)
        { // count is count of consecutive characters
            if (j == chars.size() || chars[j] != chars[j - 1])
            {
                chars[i++] = chars[j - 1];
                if (count > 1)
                    for (char digit : to_string(count))
                        chars[i++] = digit;

                count = 0;
            }
        }
        return i;

        /******* Two pointer approach ***********/
        // int n = chars.size(), i = 0, j = 1, lastIndex = 1;
        // while (i < n) {
        //     while (j < n && chars[j] == chars[i])
        //         j++;
        //     int count = j - i;
        //     if (i > 0)
        //         chars[lastIndex++] = chars[i];
        //     if (count > 1) {
        //         for (char c : to_string(count))
        //             chars[lastIndex++] = c;R
        //     i = j;
        // }
        // return lastIndex;
    }
};

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution s;
    cout << s.compress(chars);
    return 0;
}