#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1, numOperations = 0;
    while (i < j)
    {
        int temp = nums[i] + nums[j];
        if (k == temp)
        {
            numOperations++;
            i++;
            j--;
        }
        else if (k > temp)
            i++;
        else
            j--;
    }
    return numOperations;

    /************ approach 2 ****************/
    // unordered_map<int,int> freq_map; //hashmap for counting frequency of num
    // int numOperations=0;
    // for(int num:nums){
    //     if(freq_map[k-num]>0){
    //         freq_map[k-num]--;
    //         numOperations++;
    //     }
    //     else{
    //         freq_map[num]++;
    //     }
    // }
    // return numOperations;
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    int result = maxOperations(nums, k);
    cout << "Result: " << result << endl;
    return 0;
}