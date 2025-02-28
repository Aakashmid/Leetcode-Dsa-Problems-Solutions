#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> r_map; // ransom map
    unordered_map<char, int> m_map; // magazine map
    for (char ch : ransomNote)
    {
        r_map[ch]++;
    }
    for (char ch : magazine)
    {
        m_map[ch]++;
    }

    for (char ch : ransomNote)
    {
        if (r_map[ch] <= m_map[ch])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}