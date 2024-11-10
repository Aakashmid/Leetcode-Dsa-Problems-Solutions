#include<iostream>
#include<vector>
using namespace std;
/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j!=i;j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }  
        return result;
    }  
};