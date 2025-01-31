#include <iostream>
#include <string>
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0)
    {
        return b; // Base case: if remainder is 0, return b
    }
    else
    {
        return gcd(b, remainder); // Recursive case: call gcd with b and remainder
    }
}

// Function to find the greatest common divisor of two strings
string gcdOfStrings(string str1, string str2)
{
    /***************** Optimized approach *****************************/
    // Check if concatenation of str1 and str2 is equal to concatenation of str2 and str1
    if (str1 + str2 == str2 + str1)
    {
        // Determine the lengths of the strings
        int l1 = str1.length() > str2.length() ? str1.length() : str2.length();
        int l2 = str1.length() < str2.length() ? str1.length() : str2.length();
        // Return the substring of str1 from 0 to gcd of lengths  , it does not matter if we take str1 or str2
        return str1.substr(0, gcd(l1, l2));
    }
    return ""; // Return empty string if no common divisor exists




    /********Approach 1 ********/
    // The commented approach below is an alternative way to find the gcd of strings
    // It is less efficient than the approach above
    // string divisor="";
    // string smallestStr=str1.length()<str2.length()? str1:str2;
    // // Iterate through all possible lengths of the smallest string
    // for(int l=1; l<=smallestStr.length(); l++)
    // {
    //     // Check if both strings can be divided evenly by the current length
    //     if(str1.length() % l == 0 && str2.length() % l == 0)
    //     {
    //         // Extract the substring of the current length from the smallest string
    //         string pattern = smallestStr.substr(0, l);
    //         string repeated1 = "", repeated2 = "";
            
    //         // Repeat the pattern to match the length of str1
    //         for(int i=0; i<str1.length()/l; i++)
    //         {
    //             repeated1 += pattern;
    //         }
            
    //         // Repeat the pattern to match the length of str2
    //         for(int i=0; i<str2.length()/l; i++)
    //         {
    //             repeated2 += pattern;
    //         }
            
    //         // Check if the repeated patterns match the original strings
    //         if(repeated1 == str1 && repeated2 == str2)
    //         {
    //             // If they match, update the divisor to the current pattern
    //             divisor = pattern;
    //         }
    //     }
    // }
    // // Return the greatest common divisor string
    // return divisor;
}
int main(){
    string s1 = "abcabcabc";
    string s2 = "abc";
    // Output the result of gcdOfStrings function
    cout << gcdOfStrings(s1, s2) << endl;
    return 0;
}