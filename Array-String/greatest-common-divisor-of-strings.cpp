#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0)
    {
        return b;
    }
    }
    else
    {
        return gcd(b, remainder); // Recursive case: call gcd with b and remainder
    }
}

// Function to find the greatest common divisor of two strings
// This function checks if the concatenation of the two strings in both orders is equal
    {
        int l1 =
            str1.length() > str2.length() ? str1.length() : str2.length();
        int l2 =
            str1.length() < str2.length() ? str1.length() : str2.length();
        return str1.substr(0, gcd(l1, l2));
    }
    return "";

    /********Approach 1 ********/
    // string divisor="";
    // string smallestStr=str1.length()<str2.length()? str1:str2;
    // for(int l=1;l<=smallestStr.length();l++){
    //     if(str1.length()%l==0 && str2.length()%l==0){
    //         string pattern = smallestStr.substr(0,l);
    //         string repeated1="",repeated2="";
    //         for(int i=0;i<str1.length()/l;i++){
    //             repeated1+=pattern;
    //         }
    //         for(int i=0;i<str2.length()/l;i++){
    //             repeated2+=pattern;
    //         }
    //         if(repeated1==str1 && repeated2==str2){
    //             divisor=pattern;
    //         }
    //     }
    // }
    // return divisor;
}

int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    cout << gcdOfStrings(s1, s2) << endl;
    return 0;
}