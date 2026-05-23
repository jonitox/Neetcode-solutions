#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int target;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total =0;
        for(int a: nums){
            total +=a;
        }
        if(total%k) return false;
        target = total/k;
        sort(nums.rbegin(), nums.rend()); // Sort in descending order to try larger elements first, maximizing early pruning.
        return backtrack(nums, 0, k, 0, (1<<nums.size())-1);
    }

    // backtracking(+Pruning) approach, O(2^N*k)
    // Returns true if we can form 'k' valid subsets with a sum of 'target' 
    // using the available elements (mask), starting from 'idx' for the current subset
    // given the current subset's accumulated sum is 'curSum'.
    bool backtrack(vector<int>& nums, int idx, int k, int curSum, int mask) {
        if(k==0) return true;
        if(curSum == target) return backtrack(nums, 0, k-1, 0, mask);
        for(int i=idx; i<nums.size(); ++i){
            if((mask & (1<<i)) ==0) continue;
            if(curSum + nums[i] > target) continue;
            if(backtrack(nums, i+1, k, curSum+nums[i], mask ^ (1<<i))) 
                return true;
            // If an element fails to be the first item of an empty subset, 
            // the entire partition will inevitably fail.
            if(curSum == 0) return false;
        }
        return false;
    }
};

int main() {
    // test code (optional)
    return 0;
}