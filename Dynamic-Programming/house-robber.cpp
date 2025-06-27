

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Problem: Find the maximum amount of money that can be robbed from houses without robbing adjacent houses
// Approach: Use dynamic programming with two variables rob1 and rob2
// rob1 represents the max money if we rob up to two houses before the current house
// rob2 represents the max money if we rob up to the previous house
// For each house, we take maximum of (current house value + rob1) and rob2
// Then update rob1 and rob2 for next iteration

int rob(vector<int>& nums) {
     int rob1=0,rob2=0;
     int temp = 0;
     for(int num: nums){
        temp = max(rob1+num,rob2);
        rob1=rob2;
        rob2=temp;
     }   
     return rob2;
    }

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;
    return 0;
}