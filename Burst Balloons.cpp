#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+2, 1);
        for(int i=1; i<=n; ++i)
            arr[i] = nums[i-1]; // copy nums into arr with padding 1s at both ends

        vector<vector<int>> dp(n+2, vector<int>(n+2,0)); // dp[l][r]: max coins from bursting balloons between l and r (exclusive)

        for(int l=n+1; l>=0; --l)
            for(int r=l; r<=n+1; ++r)
                for(int i=l+1; i<r; ++i){
                    int coins = arr[l]*arr[i]*arr[r] + dp[l][i] + dp[i][r]; // coins from bursting i last between l and r
                    dp[l][r] = max(dp[l][r], coins);
                }

        return dp[0][n+1];
    }
};


int main() {
    // test code (optional)
    return 0;
}