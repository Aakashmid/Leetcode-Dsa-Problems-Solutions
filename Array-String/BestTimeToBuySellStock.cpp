#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        /*********** Brute force approach ************/
        // int max = 0;
        // int n = prices.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if(prices[j]>prices[i] && max<prices[j]- prices[i]){
        //             max=prices[j]-prices[i];
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        // }
        // return max;

        /********** Optimzed Approach  *************/
        int max_profit = 0;
        int cheaper = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < cheaper)
            {
                cheaper = prices[i];
            }
            else if (max_profit < prices[i] - cheaper)
            {
                max_profit = prices[i] - cheaper;
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);
    return 0;
}