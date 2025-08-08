#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    /***********Brute force approach ***************/
    // vector<int> result(nums.size());
    // result[0] = nums[0], result[1] = nums[0];
    // for (int i = 2; i < nums.size(); i++) {
    //     result[i] = result[i - 1] *
    //                 nums[i - 1]; // storing left product of ith ant ith;
    // }

    // int var = 1;
    // for (int j = result.size() - 1; j > 0; j--) {
    //     result[j] = result[j] * var;
    //     var = var * nums[j];
    // }
    // result[0] = var;
    // return result;



    /***********Optimal approach ***************/
    /*
    Approach:
    1. Count number of zeros in array and calculate product of non-zero elements
    2. For each element in array:
       - If more than 1 zero exists, all products will be 0
       - If 1 zero exists and current element is not zero, product will be 0
       - If 1 zero exists and current element is zero, product will be product of all non-zero elements
       - If no zeros, product will be total product divided by current element (because we  want product except self so we divide by current element)

    Time Complexity: O(n) where n is the size of input array
    Space Complexity: O(1) as we are modifying the input array itself

    */
    int countZero = 0;
    int product = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            countZero++;
        }
        else
        {
            product *= nums[i];
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (countZero > 1 || ((countZero == 1) && nums[i] != 0))
        {
            nums[i] = 0;
        }
        else if ((countZero == 1) && nums[i] == 0)
        {
            nums[i] = product;
        }
        else
        {
            nums[i] = product / nums[i];
        }
    }
    return nums;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}