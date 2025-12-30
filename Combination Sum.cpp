#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end()); // sort to help with early stopping in backtracking
        backTracking(0, cur, nums, target, ans);
        return ans;
    }

    // i: current index in nums, cur: current combination being built, target: remaining target sum, ans: all valid combinations found
    void backTracking(int start, vector<int>& cur, vector<int>& nums, int target, vector<vector<int>>& ans){
        if(target==0) {
            ans.push_back(cur);
            return;
        }

        for(int i= start; i< nums.size(); ++i){
            if(nums[i] > target) return; // early stopping since nums is sorted
            
            cur.push_back(nums[i]);
            backTracking(i, cur, nums, target-nums[i], ans); // not i+1 because we can reuse the same element
            cur.pop_back();
        }
        
    }
};


int main() {
    // test code (optional)
    return 0;
}