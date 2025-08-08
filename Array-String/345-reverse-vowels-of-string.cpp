#include <iostream>
#include <string>
#include <unordered_map>  // for unordered_map
using namespace std;

// Function to reverse only  vowels in a string

string reverseVowels(string s)
{
    // Create a hash map to store vowels (both uppercase and lowercase)
    unordered_map<char, int> vowels = {{'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'a', 1}, {'i', 1}, {'o', 1}, {'e', 1}, {'u', 1}};
    
    // Initialize two pointers - one at start and one at end
    int i = 0, j = s.size() - 1;
    
    // Continue until the two pointers meet
    while (i < j)
    {
        // Skip non-vowel characters from left
        if (!vowels.count(s[i]))
        {
            i++;
        }
        // Skip non-vowel characters from right
        if (!vowels.count(s[j]))
        {
            j--;
        }
        // If both characters are vowels, swap them and move pointers
        if (vowels.count(s[j]) && vowels.count(s[i]))
        {
            swap(s[j], s[i]);
            i++;
            j--;
        }
    }
    return s;
}
int main()
{
    return 0;
}