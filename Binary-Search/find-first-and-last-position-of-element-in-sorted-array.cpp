#include<iostream>
#include<vector>
using namespace std;

// find the target element index first after that from that index go forword and backword till the target is there and return boths end index
vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    int l = 0, h = size - 1;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (nums[mid] == target) {
            int first = mid, last = mid;
            
            while (last + 1 < size && nums[last + 1] == target) {
                last++;
            }

            while (first - 1 >= 0  && nums[first - 1] == target) {
                first--;
            }
            return {first,last};

        } else if (target > nums[mid]) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return {-1, -1};
}

int main(){

}