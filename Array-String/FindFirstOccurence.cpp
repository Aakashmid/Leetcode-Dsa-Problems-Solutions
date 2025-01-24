#include <iostream>
#include <string>
using namespace std;

// return first occurence of needle in haystack
int strStr(string haystack, string needle)
{
    // return haystack.find(needle);

    for (int i = 0; i <= haystack.length() - needle.length(); i++)
    {
        if (haystack.substr(i, needle.length()) == needle)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << strStr(haystack, needle) << endl;
    return 0;
}