#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
*/

int maxProfit(vector<int> &prices)
{
    int max_profit = 0;
    int cheaper = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < cheaper)
        {
            cheaper = prices[i];
        }
        else if (prices[i] > cheaper)
        {
            max_profit += prices[i] - cheaper;
            cheaper = prices[i]; //   holding one stock to sell
        }
    }
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}