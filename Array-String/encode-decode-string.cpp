/*
Approach:
1. Encode: For each string, add its length followed by '#' and the string itself
2. Decode: Parse length before '#', then extract string of that length
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encode(vector<string> &strs)
{
    string res = "";
    for (string st : strs)
    {
        res += to_string(st.length()) + "#" + st; // putting word_leng# before any word in res
    }
    return res;
}

vector<string> decode(string s)
{
    int i = 0;
    vector<string> res;
    while (i < s.length())
    {
        string num_st = "";
        int word_len = 0;
        while (s[i] != '#')
        {
            num_st += s[i];
            i++;
        }

        word_len = stoi(num_st); // get length of word

        string word = "";
        int j = i + 1;
        for (j; j < i + 1 + word_len; j++)
        {
            word += s[j];
        }

        res.push_back(word);
        i = j;
    }

    return res;
}

int main() {
    vector<string> strs = {"Hello", "World", "!"};
    
    // Encode
    string encoded = encode(strs);
    cout << "Encoded string: " << encoded << endl;
    
    // Decode
    vector<string> decoded = decode(encoded);
    cout << "Decoded strings: ";
    for(const string& str : decoded) {
        cout << str << " ";
    }
    cout << endl;
    
    return 0;
}
