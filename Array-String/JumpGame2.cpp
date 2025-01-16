#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &nums)
{
    int jump_count = 1, pos = 0;
    if (nums.size() == 1)
    {
        return 0;
    }
    while (pos + nums[pos] < nums.size() - 1)
    {
        int maxReach = 0;
        int nextPos = pos;

        // Find position that gives maximum reach (finding maximum element and its index in given range from where we can take next  jump)
        for (int i = pos + 1; i <= pos + nums[pos] && i < nums.size();
             i++)
        {
            int reach = i + nums[i];
            if (reach >= maxReach)
            {
                maxReach = reach;
                nextPos = i;
            }
        }

        pos = nextPos; // now we jump from new post nextPos
        jump_count++;
    }
    return jump_count;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}