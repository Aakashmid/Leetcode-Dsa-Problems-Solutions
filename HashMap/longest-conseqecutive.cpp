#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(),nums.end());
    int longest = 0;
    for(int num:s){
        if(s.find(num-1) == s.end()){ // this condition is to ensure we only start counting from the beginning of a sequence
            int length = 0;
            while(s.find(num+length)!=s.end()){
                length++;
            }
            longest = max(length,longest);
        }
    }
    return longest;


}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // Output: 4 (The longest consecutive elements sequence is [1, 2, 3, 4])
    return 0;
}