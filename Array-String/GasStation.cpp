#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        /************** optimized approach  1 ********************/
        int sum_gas = 0;
        int sum_cost = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum_gas += gas[i];
            sum_cost += cost[i];
        }
        if (sum_gas < sum_cost)
            return -1;

        int current_gas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0)
            {
                current_gas = 0;
                start = i + 1;
            }
        }

        return start;
        /************** optimized approach 2, o(n) ********************/
        // int start = 0;
        // int totalGas = 0;
        // int currentGas = 0;

        // for (int i = 0; i < gas.size(); i++) {
        //     int fuelGain = gas[i] - cost[i];
        //     totalGas += fuelGain;
        //     currentGas += fuelGain;

        //     if (currentGas < 0) {
        //         currentGas = 0;
        //         start = i + 1;
        //     }
        // }

        // return totalGas < 0 ? -1 : start;

        /************** Brute force approach (not good approach)
         * ********************/
        // int n = gas.size(), result = -1;
        // for (int i = 0; i < n; i++) {
        //     int c_gas = gas[i];
        //     if(c_gas>=cost[i] && n==1) return 0;
        //     if (gas[i] <= cost[i] || c_gas==0) continue;
        //     else {
        //         for (int j = i + 1; j < n; j++) {
        //             c_gas += gas[j] - cost[j - 1];
        //             if (c_gas < cost[j]) {
        //                 c_gas=0;
        //                 break;
        //             }
        //         }
        //         for (int j = 0; j <= i,c_gas!=0; j++) {
        //             if (j == 0) {
        //                 c_gas += gas[j] - cost[n - 1];
        //             } else {
        //                 c_gas += gas[j] - cost[j - 1];
        //             }
        //             if (c_gas < cost[j]) {
        //                 break;
        //             }
        //             else if(i==j){
        //                 return i;
        //             }
        //         }
        //     }
        // }
        // return result;
    }
};
int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost);
    return 0;
}