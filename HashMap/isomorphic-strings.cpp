#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


/*
isomorphic strings - twos strings s and t are isomorphic if the characters in s can be replaced to get t
*/

bool isIsomorphic(string s, string t)
{
    // unordered_map<char, int> s_map;
    // unordered_map<char, int> t_map;
    int s_map[256] = {0};  // Use arrays instead of hash maps for mapping character ASCII values  This avoids hash map overhead since we're dealing with characters
    int t_map[256] = {0};

    if (s.length() != t.length())
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s_map[s[i]] != t_map[t[i]])
        {
            return false;
        }
        else
        {
            s_map[s[i]] =
                i + 1; // use i+1 because if  i=0 then it will fail the
                       // condition if for values which are not present
                       // with value which occure once
            t_map[t[i]] = i + 1;
        }
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "add";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}