#include <iostream>
#include <vector>
#include <string>
using namespace std;
string intToRoman(int num)
{
    int Integers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string Romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    int i = 0;
    while (num > 0 && i < 13)
    {
        if (num >= Integers[i])
        {
            num -= Integers[i];
            result += Romans[i];
        }
        else
        {
            i++;
        }
    }
    return result;

    // const vector<pair<int, string>> valueSymbols{
    //     {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    //     string ans;
    //     for (const auto &[value, symbol] : valueSymbols)
    //     {
    //         if (num == 0)
    //             break;
    //         while (num >= value)
    //         {
    //             num -= value;
    //             ans += symbol;
    //         }
    //     }
    //     return ans;
    // }
}

int main()
{
    int num = 1994;
    cout << intToRoman(num) << endl;
    return 0;
}