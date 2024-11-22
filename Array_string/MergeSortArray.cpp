#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  // nums1.size is m+n

        //  brute force approach  (use sort function to sort )
        // for (int i = 0; i < n; i++) {
        //     nums1[m + i] = nums2[i];
        // }
        // sort(nums1.begin(), nums1.end());   // timecomplexity of sort function is mlogm (m is length of nums1 arr)


        //  using two pointers    // time complexity is O(M+N) where M is length of nums1 and N is length of nums2
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] < nums2[j]){
                nums1[k]=nums2[j];
                j-- ;k--;
            }
            else{
                nums1[k]=nums1[i];
                i-- ;k--;
            }
        }

        while(j>=0){
            nums1[k]=nums2[j];
            j--;k--;
        }
    }


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = nums1.size();
    int n = nums2.size();
    merge(nums1, m-n, nums2, n);   
    cout<<"After merging both arrays : "<<endl;
    for(int i=0;i<m;i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    return 0;
}