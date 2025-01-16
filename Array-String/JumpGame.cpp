#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int> &nums)
/**
 * Determines if it's possible to jump from first to last position in array.
 * Each element represents max jump length from that position.
 *
 * @param nums Vector of max jump lengths
 * @return true if last position reachable, false otherwise
 */
{

    /*************Approach 1 ****************/
    /* Approach 1: Working backwards from the goal
     * Start from the second-to-last position and work backwards to the start
     * For each position, check if we can reach the current goal from here
     * If we can reach it, update the goal to the current position
     * At the end, if goal is at position 0, we can reach the end from the start
     * Time complexity: O(n) where n is length of array
     * Space complexity: O(1) as we only use a few variables
     */

    int n = nums.size();
    int goal = n - 1;
    if (nums[0] == 0 && n - 1 == 1)
        return false;
    else
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] + i >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }

    /************ Approach 2 (not optimal)***************/
    // int furthest = 0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (i > furthest)
    //         return false;
    //     furthest = (furthest > nums[i] + i) ? furthest : nums[i] + i;
    // }
    // return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums);
    return 0;
}