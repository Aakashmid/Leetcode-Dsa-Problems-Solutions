#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    /* Optimized approach*/
    unordered_map<string, int> freq, seen;
    vector<int> res;

    int n = words.size();
    int word_size = words[0].size();
    int s_len = s.length();
    // int window_size = n*word_size;

    for (int i = 0; i < n; i++)
    {
        freq[words[i]]++;
    }

    if (s.length() < n * word_size)
    {
        return res;
    }

    /*
    we are moving pointers by word_size , to get all possible contcatenation
    we start through all position less than word_size
    */

    for (int i = 0; i < word_size; ++i)
    {
        int left = i;
        int count = 0;
        seen = {};
        for (int right = i; right <= s_len - word_size;
             right += word_size)
        {

            string word = s.substr(right, word_size);
            if (freq.count(word))
            {
                seen[word]++;
                count++;

                // if seen word count in greater than freq's, also move left
                // pointer by word_size and remove its count from seen
                while (seen[word] > freq[word])
                {
                    string left_word = s.substr(left, word_size);
                    seen[left_word]--;
                    left += word_size;
                    count--;
                }

                if (count == n)
                { // if count in equal to number of words then add index of left pointer
                    res.push_back(left);
                }
            }
            else
            { // reset when wrong word is find
                seen.clear();
                count = 0;
                left = right + word_size;
            }
        }
    }
    return res;

    /* brute force approach  */
    // unordered_map<string,int> freq,seen;
    // vector<int> res;

    // int n = words.size();
    // int word_size = words[0].size();
    // int window_size = n*word_size;

    // for(int i =0;i<n;i++){
    //     freq[words[i]]++;
    // }

    // if(s.length()<window_size){
    //     return res;
    // }

    // for (int i = 0; i <= s.length() - window_size; ++i) {
    //     // string window = s.substr(i, window_size);
    //     seen = {};
    //     for(int j =0 ;j< n ;j++){
    //         string word=s.substr(i+j*word_size,word_size);
    //         if(freq.count(word)){
    //             seen[word]++;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     if(seen == freq){
    //         res.push_back(i);
    //     }
    // }
    // return res;
}

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"cfoo", "bar"};
    vector<int> result = findSubstring(s,words);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl; // Output: 0 9 (The starting indices of the substring are 0 and 9)
    return 0;
}