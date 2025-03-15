#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
// Function to find the minimum window substring that contains all characters of string t in string s

// Approach:
// 1. Use two hash maps - one for target string t and one for current window
// 2. Use sliding window technique with two pointers (left and right)
// 3. Expand window by moving right pointer and add characters to window map
// 4. When all required characters are found, try to minimize window by moving left pointer
// 5. Keep track of minimum window length and its position
// 6. Return the minimum window substring that contains all characters of t
string minWindow(string s, string t)
{
    // If t is longer than s or empty, no valid window exists
    if (t.length() > s.length() || t == "")
    {
        return "";
    }

    // Hash maps to store character frequencies
    unordered_map<char, int> t_map;                    // For target string t
    unordered_map<char, int> window;                   // For current window in s
    int l = 0;                                         // Left pointer of sliding window
    int have = 0, need = t.length(), resLen = INT_MAX; // have: chars found, need: chars required, resLen: minimum window length
    vector<int> res(2);                                // To store start and end indices of minimum window

    // Count frequency of characters in target string
    for (char ch : t)
    {
        t_map[ch]++;
    }

    // Sliding window approach
    for (int r = 0; r < s.length(); r++)
    {
        char ch = s[r];
        window[ch]++; // Add current character to window

        // If current char is in t_map and its frequency is valid
        if (t_map.count(ch) && window[ch] <= t_map[ch])
        {
            have++; // Increment count of valid characters found
        }

        // When we have all required characters
        while (have == need)
        {
            // Update result if current window is smaller
            if (r - l + 1 < resLen)
            {
                res[0] = l;
                res[1] = r;
                resLen = r - l + 1;
            }

            // Shrink window from left
            window[s[l]]--;
            // If removing left char affects our required characters
            if (t_map.count(s[l]) && window[s[l]] < t_map[s[l]])
            {
                have--;
            }
            l++;
        }
    }

    // Return substring if found, empty string otherwise
    return resLen != INT_MAX ? s.substr(res[0], resLen) : "";
}

int main()
{
    // Test cases
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Input: s = " << s1 << ", t = " << t1 << endl;
    cout << "Output: " << minWindow(s1, t1) << endl; // Expected: "BANC"

    string s2 = "a";
    string t2 = "a";
    cout << "\nInput: s = " << s2 << ", t = " << t2 << endl;
    cout << "Output: " << minWindow(s2, t2) << endl; // Expected: "a"

    string s3 = "a";
    string t3 = "aa";
    cout << "\nInput: s = " << s3 << ", t = " << t3 << endl;
    cout << "Output: " << minWindow(s3, t3) << endl; // Expected: ""

    return 0;
}