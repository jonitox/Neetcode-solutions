#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* DP :O(n^2)
     int jump(vector<int>& nums) {
        const int INF = 10001;
        vector<int> dp(nums.size(), INF);   // dp[i]: min jumps to reach i
        dp[0]=0;
        for(int i=0; i<nums.size(); ++i){
            for(int j= i+1; j<=i+nums[i] && j<nums.size(); ++j){
                dp[j] = min(dp[j], dp[i]+1);    // jump from i to j
            }
        }
        return dp[nums.size()-1];
    }
    */

    // Greedy: O(n)
     int jump(vector<int>& nums) {
        int prevF=-1, f = 0, ans=0; // prevF: previous farthest reachable index, f: current farthest reachable index
        while(f < nums.size()-1){
            int farthest = 0; // farthest reachable index in next jump
            for(int i=prevF+1; i<=f; ++i){ 
                farthest = max(farthest, i+nums[i]);
            }
            prevF = f;
            f= farthest;
            ans++;
        }
        return ans;
     }
};



int main() {
    // test code (optional)
    return 0;
}