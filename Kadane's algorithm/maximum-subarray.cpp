#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int cs = 0;
    int ms = INT_MIN;
    for (int num : nums)
    {
        cs += num;
        ms = max(ms, cs);
        if (cs < 0)
        { // we are reseting cs as in negative if add any num it will be smaller
            cs = 0;
        }
    }
    return ms;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << maxSubArray(nums) << endl;
    return 0;
}
