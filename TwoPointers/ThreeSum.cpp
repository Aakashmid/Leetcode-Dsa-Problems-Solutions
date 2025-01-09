#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        /*************** Brute force approch ********************/
        // int n = nums.size();
        // vector<vector<int>> result;
        // set<vector<int>> set;
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n - 2; i++) {
        //     for (int j = i + 1; j < n - 1; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                     set.insert({ nums[i], nums[j], nums[k]} );
        //             }
        //         }
        //     }
        // }

        // for (auto it : set) {
        //     result.push_back(it);
        // }
        // return result;

        /***************  approch 2 ********************/
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // set<vector<int>> set;
        // vector<vector<int>> output;
        // for(int i=0; i<n-2; i++){
        //     int low = i+1, high = n-1;
        //     while(low < high){
        //         if(nums[i] + nums[low] + nums[high] < 0){
        //             low++;
        //         }
        //         else if(nums[i] + nums[low] + nums[high] > 0){
        //             high--;
        //         }
        //         else{
        //             set.insert({nums[i], nums[low], nums[high]});
        //             low++;
        //             high--;
        //         }
        //     }
        // }
        // for(auto it : set){
        //     output.push_back(it);
        // }
        // return output;

        /*************** Optimized approch ********************/
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = solution.threeSum(nums);

    // Print results
    for (const auto &triplet : result)
    {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }

    return 0;
}
