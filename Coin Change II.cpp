#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0)); // dp[i][j]: number of ways to make amount j using first i coins

        for(int i=0; i<=amount; ++i){
            dp[0][i] = (i%coins[0]==0)? 1 :0;
        }
        // dp, O(n*amount), space O(n*amount)
        for(int i=1; i<n; ++i)
            for(int j=0; j<=amount; ++j){
                dp[i][j] = dp[i-1][j];
                if(j>= coins[i])
                    dp[i][j] += dp[i][j-coins[i]];
            }
        return dp[n-1][amount];                
    }

    // dp, O(n*amount), space optimized: O(amount)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<int> dp(amount+1,0);
    //
    //     dp[0]=1;
    //     for(int i=0; i<n; ++i)
    //         for(int j=0; j<=amount; ++j){
    //             dp[j] = dp[j] + (j >= coins[i]? dp[j-coins[i]] : 0);
    //         }
    //     return dp[amount];                
    // }
};


int main() {
    // test code (optional)
    return 0;
}