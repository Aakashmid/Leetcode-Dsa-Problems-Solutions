#include <iostream>
#include <vector>
using namespace std;



// search targeted element in rotated sorted array in log(n) time complexity
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        // left sorted portion
        if (nums[l] <= nums[mid])
        {
            if (target < nums[l] || nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }

            // right sorted portion
        }
        else
        {
            if (target > nums[r] || nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target) << endl;
    return 0;
}