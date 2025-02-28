#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Summary Ranges
You are given a sorted unique integer array nums.
Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
For example, given nums = [0,1,2,4,5,7], return ["0->2","4->5","7"].
For example, given nums = [0,2,3,4,6,8,9], return ["0","2->4","6","8->9"]. (The ranges [1,3] and [5,5] are not included because they are not consecutive numbers).
*/
// vector<string> summaryRanges(vector<int> &nums)
// {
//     vector<string> summaries;
//     int i = 0;
//     string str = ""; // for storing range
//     while (i < nums.size())
//     {
//         if (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
//         {
//             if (str.length() == 0)
//             { // if its empty add start of range
//                 str += to_string(nums[i]);
//             }
//         }
//         else
//         { // when last index is reach or sequence is breaked or unique single element range
//             if (str.length() != 0)
//             { // complete range and add it in array
//                 str += "->" + to_string(nums[i]);
//                 summaries.push_back(str);
//                 str = "";
//             }
//             else
//             { // for  single element range or last element
//                 summaries.push_back(to_string(nums[i]));
//             }
//         }
//         i++;
//     }
//     return summaries;
// }



// another approach
vector<string> summaryRanges(vector<int> &nums){
    
}

int main()
{

    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> ans = summaryRanges(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
