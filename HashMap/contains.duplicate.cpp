#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

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