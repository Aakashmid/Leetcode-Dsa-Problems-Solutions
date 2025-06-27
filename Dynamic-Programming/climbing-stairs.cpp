#include <iostream>
#include <vector>
using namespace std;
int climbStairs(int n) {
        //   use dp vector array  
        vector<int> dp(n+1);
        if (n <= 3) {
            return n;
        }

        dp[0] = dp[1] = 1;
        // dp[2] = 2, dp[3] = 3;
        for (int i = 2;i<=n;i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }

int main(){
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
