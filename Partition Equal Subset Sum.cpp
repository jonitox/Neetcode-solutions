#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for(int a: nums)
            sum +=a;
        if(sum%2) return false; // odd sum cannot be partitioned into two equal subsets

        vector<bool> dp(sum/2+1); // dp[j]: whether a subset with sum j can be formed
        dp[0] = true;
        for(int i=0; i<n; ++i)
            for(int j=sum/2; j>=nums[i]; --j)
                dp[j] = dp[j] || dp[j-nums[i]];
        return dp[sum/2];
    }
};


int main() {
    // test code (optional)
    return 0;
}