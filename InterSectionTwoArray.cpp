#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //  approach -1 -> using hashmap
        // unordered_map<int,int> m;
        // vector<int> result;
        // for(int i : nums1){
        //     if(!m.count(i))
        //         m[i]=1;
        // }
        // for(int i : nums2){
        //     if(m.count(i) && m[i]==1 ){
        //         result.push_back(i);
        //         m[i]=2;
        //     }

        // }
        // return result;


        //  approach 2 - using sorting and two pointers
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int m=nums1.size(),n=nums2.size();
        // int p1=0,p2=0;
        // vector<int>ans;
        // while(p1<m&&p2<n){
        //     if(nums1[p1]==nums2[p2]){
        //         ans.push_back(nums1[p1]);
        //         while((p1+1)<m&&nums1[p1]==nums1[p1+1])
        //             p1++;
        //         p1++;
        //         while((p2+1)<n&&nums2[p2]==nums2[p2+1])
        //             p2++;
        //         p2++;
        //     }
        //     else if(nums1[p1]>nums2[p2])
        //         p2++;
        //     else p1++;
        // }
        // return ans;


        // aprroach -3 -> using set 
        unordered_set<int> s1,s2;
        for(auto &x : nums1){
            s1.insert(x);
        }

        for(auto &x : nums2){
            if(s1.find(x) != s1.end()){
                s2.insert(x);
            }
        }

        vector<int> ans (s2.begin(), s2.end());
        return ans;
    }


int main()
{
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 3, 4, 5, 6};
    vector<int> result = intersection(nums1, nums2);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
