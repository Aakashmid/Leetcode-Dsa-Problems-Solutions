#include<iostream>
#include<vector>
using namespace std;


// peak element is greater than its neighbours
// if mid is greater than its neighbours then return mid
// if mid is less than its right neighbour then search in right part(peak will be guaranteed in right part)
// if mid is less than its left neighbour then search in left part ( peak will be guaranteed in left part)
int findPeakElement(vector<int>& nums) {
    int left =0 , right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if (mid<nums.size()-1 && nums[mid]< nums[mid+1]){
            left = mid+1;
        }
        else if (mid>0 && nums[mid]< nums[mid-1]){
            right = mid-1;
        }
        else{
            return mid;
        }
    }
    return 0;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout<<findPeakElement(nums)<<endl;
    return 0;
}