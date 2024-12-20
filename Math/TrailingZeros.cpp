#include<iostream>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {

        // brute force approach
        // int ans = 0 ;
        // int factorial = fact(n);
        // while(factorial > 1){
        //     if(factorial % 10 ==0 )
        //         ans++;
        //     else{
        //         break;
        //     }
        //     factorial = factorial/10;
        // }
        // return ans;




        // Optimized approach: Counting the number of 5s in the factors of numbers from 1 to n.
        // Each trailing zero in a number's factorial is produced by a pair of factors 2 and 5.
        // Since there are always more 2s than 5s in the factors of numbers, we only need to count the number of 5s.

        int zeros_count = 0;

        // Start with 5, and keep dividing n by powers of 5 (i.e., 5, 25, 125, ...)
        // to count how many multiples of these powers are there in the range from 1 to n.
        for (int i = 5; i <= n; i *= 5)
        {
            zeros_count += n / i;
        }
        return zeros_count;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of trailing zeroes in " << n << " factorial: " << sol.trailingZeroes(n) << endl;
    return 0;
}