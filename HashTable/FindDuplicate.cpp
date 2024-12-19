#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*  find duplicate  element in an array , given - an array of size n , in which 1 to n-1  are present 
but there is a element which is twice in array , find that element */

int findDuplicate(vector<int>& arr){

    // first approach 
    int n = arr.size();
    unordered_map<int,int> nums;
    for(int i = 0; i < n;i++){
        if(nums.count(arr[i])){
            return arr[i];
        }
        else
        {
            nums[arr[i]] = 1;
        }
    }

    // second approach
    // int ans = 0 ;
    // for (int i=0;i<arr.size();i++){
    //     ans=ans^arr[i];
    // }
    // for (int i=1;i<arr.size();i++){
    //     ans=ans^i;
    // }
    // return ans;
}


int main(){
    vector<int> arr = {1,3,5,2,4,4};  // here n=6,  then element will be till 5 and one element is twice  
    cout<<findDuplicate(arr)<<endl;
    return 0;
}