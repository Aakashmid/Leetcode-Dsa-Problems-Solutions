#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> map;
    unordered_map<int, int> occurences; // for counting same number of occurences
    for (int num : arr)
    {
        if (map.count(num) == 0)
        {
            map[num] = 1;
        }
        else
        {
            map[num]++;
        }
    }

    for (const auto &pair : map)
    {
        if (occurences.count(pair.second) > 0)
        { // pair.second is value of pair and first is key
            return false;
        }
        else
        {
            occurences[pair.second]++;
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    string result = uniqueOccurrences(arr) ? "true" : "false";
    cout << result;
    return 0;
}