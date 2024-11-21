#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0, j = 0; // i - string s pointer , j- string t pointer
    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i == s.length(); // return true if all element of s is in t else false
}

int main()
{
    string s = "", t = "";
    cout << "Enter string s :";
    cin >> s;
    cout << "Enter string t :";
    cin>>t;
    /*
    cin.ignore();  // Ignore leftover newline from the input buffer  , so we can go to direct to new line
    cout << "Enter stabcring t :";
    getline(cin, t);
    */
    if (isSubsequence(s, t))
        cout << s << " is a subsequence of " << t << endl;
    else
        cout << s << " is not a subsequence of " << t << endl;

    return 0;
}