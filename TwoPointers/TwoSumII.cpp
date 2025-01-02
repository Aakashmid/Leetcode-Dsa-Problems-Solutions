/*
Given a 1-indexed sorted array, find two numbers that add up to target.
Return indices (index1, index2) added by one as array [index1, index2].
Exactly one solution exists. No duplicate elements. Use constant space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{

    // brute force approch ( time limit exceeded for large array)
    //  for(int i = 0;i<numbers.size();i++){
    //      for(int j=i+1;j<numbers.size();j++){
    //          if (numbers[i]+numbers[j] == target){
    //              result.push_back(i+1);result.push_back(j+1);
    //              return result;
    //          }
    //      }
    //  }

        int s = 0, l = numbers.size() - 1;
    while (s < l)
    {
        if (numbers[s] + numbers[l] == target)
            return {s + 1, l + 1}; // we added 1 in both index because our array in 1-indexed array
        else if (numbers[s] + numbers[l] < target)
        {
            s++;
        }
        else
            l--;
    }
    return {};
}

int main()
{
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array(should be in increasing order ) : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);
    if (!result.empty())
    {
        cout << "Indices of the two numbers that add up to the target are: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers add up to the target." << endl;
    }
    return 0;
}