#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    // time complexity  - logn
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] >
            nums[right]) { // because in rotated sorted array minimum value
                           // is present in right portion
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];

    // time complexity - nlog(n)
    // sort(nums.begin(),nums.end());
    // return nums[0];
}

int main(){
    vector<int> nums = {3,4,5,1,2};
    cout << findMin(nums) << endl;
    return 0;
}