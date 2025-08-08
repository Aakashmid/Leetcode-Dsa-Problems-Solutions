#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        int numOf_1_bits(int n) {
            int res = 0;
            while (n > 0) {
                // here in each iteration number of 1 bits is reduced by 1 (so it will find number of bits in least time )
                n = n & (n - 1);
                res++;
            }
            return res;
        }
        vector<int> countBits(int n) {
    
            // brute force approach , time complexity - o(nlogn)
            // vector<int> result;
            // for(int i=0;i<=n;i++){
            //     result.push_back(numOf_1_bits(i));
            // }
            // return result;
    
    
            // optimal approach(use dynamic programming) 
            /*
            Explanation - 
            1. We create a dp array of size n+1
            2. We initialize dp[0] = 0, as there are no bits in 0
            3. We iterate from 1 to n, and for each i, we find the largest power of 2 less than or equal to i (offset).
            4. We set dp[i] = 1 + dp[i - offset], where offset is the largest power of 2 less than or equal to i.
            5. This works because the number of bits in i is equal to the number of bits in (i - offset) plus 1 (for the bit at position offset).
            6. We return the dp array.
            7. The time complexity is O(n) and space complexity is O(n).
            */
            vector<int> dp(n+1);
            int offset = 1;
            for(int i = 1 ;i<=n;i++){
                if(offset*2 == i){
                    offset = i;
                }
                dp[i]= 1+dp[i-offset];
            }
            return dp;
        }
    };


int main(){
    Solution s;
    int n = 5;
    vector<int> result = s.countBits(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }


    return 0;
}