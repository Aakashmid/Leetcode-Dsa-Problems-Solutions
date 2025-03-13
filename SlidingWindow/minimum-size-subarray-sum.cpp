
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


// have to find minimum length of subarray whose sum is greater than or equal to target
int minSubArrayLen(int target, vector<int>& nums) {

    // optimized approach
    int start = 0, sum = 0, min_len = INT_MAX;   // start -left pointer , i - right pointer
    int i = 0;
    while (i < nums.size()) {
        sum += nums[i++];
        while (sum >= target) {
            min_len = min(min_len, i - start);
            sum -= nums[start++];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;




    // approach 2 
    // int n = nums.size(), len = INT_MAX;
    //         vector<int> sums(n + 1, 0);
    //         for (int i = 1; i <= n; i++) {
    //             sums[i] = sums[i - 1] + nums[i - 1];
    //         }
    //         for (int i = n; i >= 0 && sums[i] >= s; i--) {
    //             int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
    //             len = min(len, i - j + 1);
    //         }
    //         return len == INT_MAX ? 0 : len;
}



int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3, 5};
    cout << minSubArrayLen(7, nums) << endl;

    return 0;
}