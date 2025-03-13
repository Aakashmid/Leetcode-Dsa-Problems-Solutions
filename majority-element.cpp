#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
    int majorityElement(vector<int> &nums)
    {

        // hash map approach
        // unordered_map<int,int> m;
        // if(nums.size()==1)
        //     return nums[0];
        // for (int num:nums){
        //     if(m.count(num)){
        //         m[num]+=1;
        //         if(m[num]>nums.size()/2)
        //             return num;
        //     }
        //     else{
        //         m[num]=1;
        //     }
        // }
        // return 0;

        // one of the approach is sort array using sort method and return element at n/2 position becaue majority element is always be at middle in sorted array



        // Moore's Voting Algorithm
        int count = 0;
        int candidate = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};


int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    Solution solution;
    int majority = solution.majorityElement(nums);
    cout << "The majority element is: " << majority << endl;

    return 0;
}