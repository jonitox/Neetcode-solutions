#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(3, 0); // space optimized DP: only keep last two states
        dp[0] =0;
        dp[1] =0;
        for(int i=2; i<=n; ++i){
            dp[i%3] = min(dp[(i-2)%3] + cost[i-2], dp[(i-1)%3]+ cost[i-1]); // min cost to reach step i
        }
        return dp[n%3];

    }
};

int main() {
    // test code (optional)
    return 0;
}