#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

vector<int> plusOne(vector<int> &digits)
{

    // first approach
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;

    // second approach
    // int carry = 1; // Start with a carry of 1, as we are adding one to the number
    // for (int i = digits.size() - 1; i >= 0; --i) {
    //     int sum = digits[i] + carry;
    //     digits[i] = sum % 10; // Update the current digit
    //     carry = sum / 10; // Calculate the new carry
    //     if (carry == 0) {
    //         return digits; // If no carry, return early
    //     }
    // }
    // // If there's still a carry, it means we need to add a new digit at the front
    // digits.insert(digits.begin(), carry);
    // return digits;
}

int main()
{

    vector<int> digits = {9, 9, 9}; // Example input
    vector<int> result = plusOne(digits);

    cout << "Result: ";
    for (int digit : result)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}