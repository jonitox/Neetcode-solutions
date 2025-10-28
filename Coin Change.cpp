#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int INF = 99999999;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INF); // dp[j]: min number of coins to make amount j
        dp[0]= 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<= amount; ++j)
                dp[j] = min(dp[j], j>=coins[i]? dp[j-coins[i]]+1:INF);

        return dp[amount] == INF? -1: dp[amount];
    }
};


int main() {
    // test code (optional)
    return 0;
}