#include <iostream>
#include <vector>
#include <climits> // Include climits for INT_MAX
using namespace std;

// Function to check if there exists an increasing triplet subsequence
bool increasingTriplet(vector<int>& nums) {
    int n1 = INT_MAX, n2 = INT_MAX;
    for (int num : nums) {
        if (num <= n1) {
            n1 = num; // Update n1 to the smallest value
        } else if (num <= n2) {
            n2 = num; // Update n2 to the second smallest value
        } else {
            return true; // Found a number greater than both n1 and n2
        }
    }
    return false; // No increasing triplet found
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    string result = increasingTriplet(nums) ? "true" : "false";
    cout << result;
    return 0;
}