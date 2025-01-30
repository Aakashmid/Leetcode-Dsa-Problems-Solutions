#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }
        // for(int i=0;i<s.length();i++){
        //     if((s[i]==' ' && word!="") || (i==s.length()-1 && )){
        //         words.push_back(word);
        //         word="";
        //         continue;
        //     }
        //     else if (s[i]!=' '){
        //         word+=s[i];
        //     }

        // }

        reverse(words.begin(), words.end());

        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)
                result += " ";
            result += words[i];
        }

        return result;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    return 0;
}