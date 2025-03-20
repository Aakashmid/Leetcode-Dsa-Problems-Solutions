#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // optimal approach
    vector<vector<string>> res;
    map<string, vector<string>> anagrams;
    for (int i = 0; i < strs.size(); i++) {
        // vector<int> cnt(26,0);
        // for (char ch : strs[i]) {
        //     cnt[ch - 'a'] += 1;
        // }
        // if (anagrams.count(cnt))
        //     anagrams[cnt].push_back(strs[i]);
        // else
        //     anagrams[cnt]={strs[i]};
        string word = strs[i];
        sort(word.begin(),  word.end());
        anagrams[word].push_back(strs[i]);
    
    }

    for (auto& pair : anagrams) {
        res.push_back(pair.second);
    }
    return res;






    // brute force approach (only for small number of strings , getting error time limit exceeded )
    // vector<vector<string>> res;
    // unordered_map<int, bool> m;  // track already added anagrams

    // for (int i = 0; i < strs.size(); i++) {
    //     if (!m.count(i)) {
    //         res.push_back({strs[i]});
    //         m[i] = true;
    //         for (int j = 0; j < strs.size(); j++) {
    //             if (i != j && !m.count(j) &&
    //                 isAnagram(strs[i], strs[j])) {
    //                 res[res.size() - 1].push_back(strs[j]);
    //                 m[j] = true;
    //             }
    //         }
    //     }
    // }
    // return res;
}


int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}