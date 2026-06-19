#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // dp bottom-up approach. time O(n*m), space O(m), where n= nums.size(), m = sum of all elements in array
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp;// dp[x] = # of ways to make x so far.
        dp[0] =1;
        for(int a: nums){
            unordered_map<int, int> next;
            for(auto& [x,y] : dp){
                next[x+a] += y;
                next[x-a] += y;
            }
            dp = next;
        }    
        return dp[target];
    }
};





int main() {
    // test code (optional)
    return 0;
}