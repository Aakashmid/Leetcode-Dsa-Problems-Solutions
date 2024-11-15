#include<iostream>
using namespace std;

// find square root of number without using any built in function  , return the square root of x rounded down to the nearest integer
class Solution {
public:

    // using binary search approach to find sqrt
    int mySqrt(int x) {
        int s = 1; // start
        int l = x; // end
        int mid = 0;
        while (s <= l) {
            mid = s + (l - s) / 2;
            if ( mid == x/mid)
                return mid;
            else if (mid >x/mid)
                l = mid - 1;
            else
                s = mid + 1;
        }
        return l;
    }
};

int main (){
    Solution obj;
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Square root of " << x << " is " << obj.mySqrt(x) << endl;
    return 0;
}