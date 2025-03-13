#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {

    unordered_map<char, bool> m;
    int l = 0, r = 0, max_len = 0;
    while (r < s.length()) {
        while(m[s[r]]) {
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

}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}