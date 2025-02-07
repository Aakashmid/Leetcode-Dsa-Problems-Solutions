#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int left_sum = 0, sum = 0, right_sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        right_sum = sum - nums[i] - left_sum;
        if (right_sum == left_sum)
        {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}


int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout <<"Pivot index is : " <<pivotIndex(nums);
}