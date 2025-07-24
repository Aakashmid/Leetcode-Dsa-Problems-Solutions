#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//  find max length of substring of same char  with at most k replacements
int characterReplacement(string s, int k)
{
    /*
    Approach - count the max occured char if difference between length of substring and maxF is less than k that means we can replace those less occured chars ( so we calc res every time for this case)
    */

    // unordered_map<char,int> count;
    // int res = 0;
    // int l=0;
    // int maxF = 0 ;
    // for(int r=0;r<s.length();r++){
    //     count[s[r]]++;
    //     maxF = max(count[s[r]],maxF);
    //     while((r-l+1)-maxF > k){
    //         count[s[l]]--;
    //         l++;
    //     }
    //     res = max(res,r-l+1);
    // }

    // return res ;

    // brute force approach
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> count;
        int maxF = 0;
        for (int j = i; j < s.size(); j++)
        {
            count[s[j]]++;
            maxF = max(maxF, count[s[j]]);
            if ((j - i + 1 - maxF) <= k)
            { // j-i+1 is length of window
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl; // Output: 4
    return 0;
}