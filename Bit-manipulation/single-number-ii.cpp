#include<iostream>
#include <vector>
using namespace std;


// incomplete 
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int num : nums) {
            num = num >> i & 1; // get ith bit
            sum += num;
        }
        if (sum % 3 != 0) {
            res += 1 << i;
        }
    }
    return res;
}


int main(){
    vector<int> nums = {2,2,3,2};
    cout << singleNumber(nums) << endl; // Output: 3
    return 0;
}