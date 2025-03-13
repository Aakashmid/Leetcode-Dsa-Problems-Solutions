
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


// have to find maximum average of a subarray of size k
double findMaxAverage(vector<int>& nums, int k) {
    double res=INT_MIN;      
    int r=0,l=0;
    int sum=0;
    while(r<nums.size()){
        while(r-l !=k){
            sum+=nums[r++];
        }
        res=max(res,(double)sum/k);
        sum-=nums[l++];        
    }
    return res;
}

int main(){
    vector<int>  nums = {2, 3, 1, 2, 4, 3, 5};
    cout<<findMaxAverage(nums,3)<<endl;
    return 0;
}