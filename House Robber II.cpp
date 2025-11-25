#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n);
        // rob houses from 0 to n-2
        dp[0] = nums[0];
        for(int i=1; i<n-1; ++i){
            dp[i] = i==1? dp[0] : max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans = dp[n-2];

        // rob houses from 1 to n-1
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2; i<n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        ans = max(ans, dp[n-1]);
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}