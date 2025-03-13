#include<iostream>  
#include<string>
#include<unordered_set>
using namespace std;

int maxVowels(string s, int k) {
    // unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    // int max_vowels = 0;
    // int l = 0;
    // int temp_num = 0;
    // for (int r = 0; r < s.length(); r++) {
    //     if (vowels.count(s[r])) {
    //         temp_num++;
    //     }
    //     if (r - l == k) {
    //         if (vowels.count(s[l])) {
    //             temp_num--;
    //         }
    //         l++;
    //     }
    //     max_vowels = max(temp_num, max_vowels);
    // }
    // return max_vowels;




    // Approach 2
    // Store current count of vowels in currCount
    // and maximum currCount occurred in ans
    int currCount = 0;
    int ans = 0;

    // An array to mark all the vowels' position to true
    bool vowels[26] = {false};
    vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = true;

    // Sliding window implementation
    for (int i = 0; i < s.length(); i++) {

        // if any vowel is removed from left-> decrement
        if (i >= k and vowels[s[i - k] - 'a']) {
            currCount -= 1;
        }

        // if any vowel is inserted from right-> increment
        if (vowels[s[i] - 'a']) {
            currCount += 1;
        }

        // Store maximum occurence of currCount in ans
        ans = max(ans, currCount);
    }

    return ans;
}


int main(){
    string s = "abciiidef";
    int k = 3;
    cout << maxVowels(s, k) << endl;
    return 0;
}