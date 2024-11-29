#include<iostream> 
#include<vector>
using namespace std;

// This function removes duplicates from an array and returns the new length.  (in sorted array a element can appears atmost twice)

int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int j=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int j = removeDuplicates(nums);
    cout<<"No of unique elements "<<j<<endl;
    for(int i=0;i<j;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}