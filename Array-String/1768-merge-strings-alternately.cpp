#include <iostream>
#include <string>
using namespace std;

// Function to merge two strings alternately by taking characters from each string one by one
// Example: word1 = "abc", word2 = "pqr" -> result = "apbqcr"
string mergeAlternately(string word1, string word2)
{
    int i = 0, len = 0;
    string result = "";
    // Get the length of the longer string
    len = word1.length() > word2.length() ? word1.length() : word2.length();
    // Iterate until we reach the end of the longer string
    while (i < len)
    {
        // Add character from word1 if we haven't reached its end
        if (i < word1.length())
        {
            result += word1[i];
        }
        // Add character from word2 if we haven't reached its end
        if (i < word2.length())
        {
            result += word2[i];
        }
        i++;
    }
    return result;
}

int main()
{
    string word1 = "abc";
    string word2 = "pqr";
    cout << mergeAlternately(word1, word2) << endl;
    return 0;
}