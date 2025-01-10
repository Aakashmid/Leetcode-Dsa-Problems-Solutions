#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        /*************** Brute force approach *******************/
        // int n = nums.size();
        // if (n > 1) {
        //     for (int i = 0; i < k; i++) {
        //         int value = nums[n - 1];
        //         nums.erase(nums.begin() + n - 1);
        //         nums.insert(nums.begin(), value);
        //     }
        // }

        /*************** brute force approach 2*******************/
        // int n=nums.size(),mid=0,temp=0;
        // if(n%2!=0){
        //     mid = n/2;
        // }
        // int start=0,last=n-k;
        // while(last<n){
        //     temp=nums[start];
        //     nums[start]=nums[last];
        //     nums[last]=temp;
        //     start++;last++;
        // }
        // if(mid!=0){
        //     temp=nums[mid];
        //     nums.erase(nums.begin()+mid);
        //     nums.push_back(temp);
        // }

        /*
        For k=2
        12345 -> 54321   // reverse whole array
        54321->45321     // reverse first k elements
        45321->45123     // reverse last n-k elements

        case - when k>n  // n - size of array
        k=k%n;

        */
        /************** Optimized Approach ******************/
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution obj;
    obj.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}