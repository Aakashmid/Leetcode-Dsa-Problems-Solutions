#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force approach
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j!=i;j++){
        //         if(nums[i]+nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }  

        unordered_map<int,int> numMap; 
        // creating hash table 
        for(int i=0;i<nums.size();i++){
            numMap[nums[i]]=i;            
        }

        for(int i=0;i<nums.size();i++){
            int diff= target - nums[i];
            if(numMap.count(diff) && numMap[diff]!=i)   // check is diff in numMap or not  and indices of both integer is  should be different 
                return {i,numMap[diff]};
        }
        return {};
        
    }  
int main(){
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to the target are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}