#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    int result = 0;
    unordered_map<char, int> rv_map = {// roman values has map
                                       {'I', 1},
                                       {'V', 5},
                                       {'X', 10},
                                       {'L', 50},
                                       {'C', 100},
                                       {'D', 500},
                                       {'M', 1000}};

    result = rv_map[s[0]];
    for (int i = 1; i < s.length(); i++)
    {
        if (rv_map[s[i - 1]] < rv_map[s[i]])
        {
            result += rv_map[s[i]] - 2 * rv_map[s[i - 1]];
        }
        else
        {
            result += rv_map[s[i]];
        }
    }
    return result;
}

int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}