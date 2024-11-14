#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        // another approach is to iterate in only one direction
        // int L = 0;
        // while (L < nums.size())
        // {
        //     if (nums[L] == val)
        //     {
        //         nums.erase(nums.begin() + L);
        //     }
        //     else
        //     {
        //         L++;
        //     }
        // }


        int L = 0;
        int R = nums.size() - 1;
        while (L <= R)
        {
            if (nums[L] == val)
            {
                nums.erase(nums.begin() + L);
                R--;
            }
            else if (nums[R] == val)
            {
                nums.erase(nums.begin() + R);
                R--;
            }
            else
            {
                L++;
                R--;
            }
        }
        return nums.size();
    }
};

int main()
{
    int n, val;
    cout << "Enter size of input array : " << endl;
    cin >> n;
    vector<int> nums(n);
    for (auto &num : nums)
    {
        cin >> num;
    }
    cout << endl;

    cout << "Enter value to remove : " << endl;
    cin >> val;
    cout << endl;

    //  Create an instance of Solution and call the method
    Solution solution;
    int newLength = solution.removeElement(nums, val);

    //  Print the result
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}