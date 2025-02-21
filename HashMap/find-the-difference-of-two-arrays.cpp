#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
question :  find difference of two sets
*/
vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> diff1;
    vector<int> diff2;

    for (int num : set1)
    {
        if (set2.count(num) == 0)
        {
            diff1.push_back(num);
        }
    }

    for (int num : set2)
    {
        if (set1.count(num) == 0)
        {
            diff2.push_back(num);
        }
    }

    return {diff1, diff2};
}

int main(){
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result = findDifference(nums1, nums2);
    for (const auto& pair : result)
    {
        for (int num : pair)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}