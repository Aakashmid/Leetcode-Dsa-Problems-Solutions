#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
bool containsDuplicate(vector<int>& nums) {

    // approach 2
    // sort(nums.begin(), nums.end());
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i] == nums[i - 1])
    //         return true;
    // }
    // return false;

    // approach 1
    unordered_map<int,bool> m;
    for(int i=0;i<nums.size();i++){
        if(m.count(nums[i])){
            return true;
        }
        else{
            m[nums[i]]=true;
        }
    }
    return false;

}


int main(){
    vector<int> nums = {1,2,3,4,5};
    cout<<containsDuplicate(nums)<<endl;
    return 0;
}