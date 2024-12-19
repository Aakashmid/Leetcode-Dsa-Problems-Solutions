#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // brute force approach would be using two forloop  and then find area using two elements and check whether it is max or not ( but it takes o(n^2) time complexity )


    // optimized approach using two pointers (left and right)
    int maxArea(vector<int>& height) {
        int max = 0, left= 0 ;
        int right= height.size() - 1;
        while (left< right) {
            int temp=0;
            if (height[left] < height[right]){
                temp = (right-left)*height[left];
                left++;
            }
            else{
                 temp = (right-left)*height[right];
                right--;
            }

            if( max<temp)
                max = temp;
        }
        return max;
    }
};

int main(){
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum area: " << sol.maxArea(height) << endl;
    return 0;
}