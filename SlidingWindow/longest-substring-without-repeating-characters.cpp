#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s)
{

    // approach 1 (sliding window optimal)
    unordered_map<char, bool> m;
    int l = 0, r = 0, max_len = 0;
    while (r < s.length())
    {
        while (m[s[r]])
        {
            m[s[l++]] = false;
        }
        m[s[r++]] = true;
        max_len = max(max_len, r - l);
    }

    return max_len;

    // unordered_set<char> m_set;
    // int res=0;
    // int l=0,r=0;
    // while(r<s.length()){
    //     while(m_set.count(s[r])){
    //         m_set.erase(s[l++]);
    //     }
    //     m_set.insert(s[r++]);
    //     res=max(res,r-l);
    // }
    // return res;



    // brute force approach (sliding window)
    // unordered_set<char> hash_set; // hash_set for storing char
    //     int maxLen = 0;
    //     string st="" ; //  string for non repeating  substring
    //     for(char ch:s){
    //         if(hash_set.count(ch)){
    //             int count=0;
    //             while(hash_set.count(ch)){
    //                 if(count==0){
    //                     // calculating maxLen only first because we are removing char and length will be max ony first time
    //                     maxLen = max(static_cast<int>(st.length()),maxLen);
    //                 }
    //                 hash_set.erase(st[0]);
    //                 st.erase(0, 1); //  erase from st while duplicate present
    //             }
    //             hash_set.insert(ch);
    //             st+=ch;
    //         }else{
    //             st+=ch;
    //             hash_set.insert(ch);
    //         }
    //     }

    //     return max(maxLen,static_cast<int>(st.length()));
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}