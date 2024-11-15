#include <iostream>
#include <cctype>
using namespace std;

// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int L = 0, R = s.length() - 1;
        while (L <= R)
        {
            if (!isalnum(s[L]))  // if char is not alphanumeric skip that char , and continue to the next iteration
            {
                L++;
                continue;
            }
            if (!isalnum(s[R]))
            {
                R--;
                continue;
            }
            if (tolower(s[L]) != tolower(s[R]))
            {
                return false;
            }
            else
            {
                L++;
                R--;
            }
        }
        return true;
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    Solution obj;
    obj.isPalindrome(str) ? cout<<str<<" is a palindrome"<<endl : cout<<str<<" is not a palindrome"<<endl;
    return 0;
}