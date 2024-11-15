#include <iostream>
#include <vector>
#include <algorithm> // Required for reverse

using namespace std;

class Solution
{
public:
    // our function to return sorted array of squares of numbers of array given to input
    vector<int> sortedSquares(vector<int> &nums)  // using two pointers method or algorithm
    {
        vector<int> result;
        int L = 0, R = nums.size() - 1;  // initializing two pointers 
        while (L <= R)
        {
            if (abs(nums[L]) > abs(nums[R]))
            {
                result.push_back(nums[L] * nums[L]);
                L++;
            }
            else
            {
                result.push_back(nums[R] * nums[R]);
                R--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    // vector<int> nums = {-4, -1, 0, 3, 10};

    int n ;
    cout<<"Enter size of vector: "<<endl;
    cin>>n;
    vector<int> nums(n) ;
    for(auto &num:nums){
        cin>>num;
        cout<<" "; 
    }
    
    //  Create an instance of Solution and call the method
    Solution solution;
    vector<int> result = solution.sortedSquares(nums);


    //  Print the result
    cout << "Sorted squares: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}