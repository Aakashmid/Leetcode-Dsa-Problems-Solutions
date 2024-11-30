#include <iostream>
#include<vector>
using namespace std;

/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appears at most twice, return an array of all the integers that appears twice.
*/
vector<int> findDuplicates(vector<int> &nums)
{

    // brute force approach
    // unordered_map<int,int> num_map;
    // vector<int> result;
    // for(int i=0;i<nums.size();i++){
    //     if(num_map.count(nums[i]))
    //         result.push_back(nums[i]);
    //     else
    //         num_map[nums[i]]=1;
    // }
    // return result;



    // optimized approach
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = abs(nums[i]) - 1;
        // Since it is already -ve, that means it has occurred earlier.
        // Add this to the output list.
        if (nums[x] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        // Mark the index -ve.
        else
        {
            nums[x] *= -1;
        }
    }
    return ans;
}



int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    cout << "Duplicates: ";
    for (int i : duplicates)
        cout << i << " ";
}