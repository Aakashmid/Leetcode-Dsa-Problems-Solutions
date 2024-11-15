#include <iostream>
#include<climits>
#include <algorithm>
using namespace std;

bool isPalindrome(int x)
{
    int reverse = 0, n = x;
    while (n != 0)
    {
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10){   // if number is out of range (its maximum or minimum)
            cout<<"ERROR: Invalid number ";
            return false;
        }
        reverse = (reverse * 10 + (n % 10));   
        n = n / 10;
    }

    if (abs(reverse) == x)
        return true;
    else
        return false;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;
    return 0;
}