#include <iostream>
#include <sstream>
using namespace std;

int lengthOfLastWord(string s)
{

    /******* Brute force approach*********/
    //  string last_word ;
    //  stringstream ss(s);
    //  while(ss >> last_word){
    //  }
    //  return last_word.length();

    /******* optimized  approach*********/
    int length = 0;
    int i = s.length() - 1;
    for (i; i >= 0; i--)
    {
        if (s[i] == ' ' && length != 0)
            break;
        if (s[i] != ' ')
        {
            length += 1;
        }
    }
    return length;
}

int main()
{
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}