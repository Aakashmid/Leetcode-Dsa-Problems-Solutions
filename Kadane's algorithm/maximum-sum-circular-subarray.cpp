#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{

    // incomplete 
    // int n = nums.size();
    // int ms = INT_MIN;
    // int cs = 0;
    // for(int i =0;i <n;i++){
    //     for(int j = i+1;j%n < n ;j++ ){
    //         cs +=nums[j%n];
    //         ms = max(ms,cs);
    //         if(cs < 0 ){
    //             cs = 0;
    //         }
    //         if(j%n==i){
    //             break;
    //         }
    //     }
    // }
    // return ms;

    int globMax = nums[0], total = nums[0];
    int currMax = nums[0], currMin = nums[0], globMin = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];
        currMax = max(currMax + num, num);
        currMin = min(currMin + num, num);
        total += num;

        globMax = max(globMax, currMax);
        globMin = min(globMin, currMin);
    }

    if (globMax > 0)
    {
        return max(globMax, total - globMin);
    }
    return globMax;
}

int main()
{
    return 0;
}