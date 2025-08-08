#include<iostream>
#include<vector>
using namespace std;
    int removeDuplicates(vector<int>& nums) {
        // int s=0;
        // unordered_map<int,int> numMap;
        // while(s<nums.size()){   // taking more run time
        //     if(numMap.count(nums[s])){
        //         nums.erase(nums.begin()+s);
        //     }
        //     else{
        //         numMap[nums[s]]=s;
        //         s++;
        //     }
        // }


        // int i = 0,j = i + 1;
        // while (j < nums.size()) {
        //     if (nums[i] == nums[j])
        //         nums.erase(nums.begin() + j);
        //     else {
        //         i = j;
        //         j = i + 1;
        //     }
        // }
        // return nums.size();


        int j = 1;
        for (int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
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