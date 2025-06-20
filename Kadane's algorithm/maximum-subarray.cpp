#include<iostream>
#include<vector>
using namespace std;

    int maxSubArray(vector<int>& nums) {
        int cs = 0;
        int ms = INT_MIN;
        for(int num:nums){
            cs+=num;
            ms = max(ms,cs);
            if(cs< 0){  // we are reseting cs as in negative if add any num it will be smaller 
                cs = 0;
            }
        }
        return ms;
    }

 int main(){

 }