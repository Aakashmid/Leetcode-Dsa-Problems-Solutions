#include<iostream>
#include<vector>
using namespace std;


// return postion where target should be inserted or present  in sorted array in log(n) time complexity
int searchInsert(vector<int>& nums, int target) {
    int low =0, high = nums.size()-1;
    while(low<=high ){
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high =mid-1;
        }
    }
    return low;
}


int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    // int target = 8;
    cout<<searchInsert(nums,target)<<endl;
    return 0;
}