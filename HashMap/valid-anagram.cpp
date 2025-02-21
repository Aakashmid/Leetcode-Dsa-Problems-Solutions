#include <iostream>
#include <unordered_map>
using namespace std;


bool isAnagram(string s, string t)
{

    // Approach 1 (using sort)
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());
    // if(s.length()!=t.length()){
    //     return false;
    // }
    // for(int i=0;i<s.length();i++){
    //     if(s[i]!=t[i]){
    //         return false;
    //     }
    // }
    // return true;

    // Approach 2
    unordered_map<char, int> m; // created map for tracking  count frequency of char
    if (s.length() != t.length())
    {
        return false;
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (!m.count(s[i]))
        {
            m[s[i]] = 1;
        }
        else
        {
            m[s[i]] += 1;
        }
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (!m.count(t[i]) || m[t[i]] == 0)
        {
            return false;
        }
        else
        {
            m[t[i]] -= 1;
        }
    }
    return true;
}


int main()
{
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}