// Include necessary header files
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

/**
 * Function to check if a string follows a given pattern
 * @param pattern: The pattern string containing letters
 * @param s: The input string containing words
 * @return: true if string follows the pattern, false otherwise
 */
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> m; // map to store pattern to word mapping
    set<string> wam;               // word already mapped with a letter in pattern
    vector<string> words;          // vector to store individual words from input string

    // Split input string into words
    string word = "";
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || i == s.length())
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += s[i];
        }
    }

    // Check if number of words matches pattern length
    if (words.size() != pattern.length())
    {
        cout << words.size() << " " << pattern.length() << endl;
        cout << "1";
        return false;
    }

    // Check pattern matching
    for (int i = 0; i < pattern.length(); i++)
    {
        // If pattern character already exists in map
        if (m.count(pattern[i]))
        {
            // Check if current word matches the mapped word
            if (m[pattern[i]] != words[i])
            {
                cout << "second false " << i << words[i];
                return false;
            }
        }
        else
        {
            // If word is not already mapped to any pattern character
            if (wam.count(words[i]) != 1)
            {
                m[pattern[i]] = words[i]; // Map pattern character to word
                wam.insert(words[i]);     // Mark word as mapped
            }
            else
            {
                return false; // Word already mapped to different pattern character
            }
        }
    }

    return true; // Pattern matches successfully

    // another approach
    // unordered_map<char, int> p_map;   // pattern char count
    // unordered_map<string, int> w_map; // string word count
    // istringstream in(s);
    // int i = 0, n = pattern.size();
    // for (string word; in >> word; ++i)
    // {
    //     if (i == n || p_map[pattern[i]] != w_map[word])
    //         return false;
    //     p_map[pattern[i]] = w_map[word] = i + 1;
    // }
    // return i == n;
}

/**
 * Main function to test the wordPattern function
 */
int main()
{
    cout << wordPattern("abba", "dog cat cat dog");
    return 0;
}