#include<iostream>
#include<vector>
using namespace std;



int trap(vector<int>& height) {
    //  Brute force approach
    int n = height.size();
    vector<int> maxleft(n);
    vector<int> maxright(n);
    int max = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        maxleft[i] = max;
        if (max < height[i]) {
            max = height[i];
        }
    }
    max = 0;
    for (int i = n - 1; i >= 0; i--) {
        maxright[i] = max;
        if (max < height[i]) {
            max = height[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int minBorder=min(maxleft[i], maxright[i]);
        if ((minBorder - height[i])>=0) {
            ans+=minBorder-height[i];
        }
    }

    return ans;
}



int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
    return 0;
}