#include <iostream>
#include <vector>
#include <algorithm>  // for max_element
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int max = candies[0];
    //  int max=*max_element(candies.begin(),candies.end());   // taking much time to calculate max
    vector<bool> result;

    for (int i = 1; i < candies.size(); i++)
    {
        if (candies[i] > max)
        {
            max = candies[i];
        }
    }
    for (int j = 0; j < candies.size(); j++)
    {
        if (max - candies[j] <= extraCandies)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the number of candies: ";
    cin >> n;
    vector<int> candies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
    }
    int extraCandies;
    cout << endl
         << "Enter the number of extra candies: ";
    cin >> extraCandies;
    cout<<"Result: ";
    vector<bool> result = kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}