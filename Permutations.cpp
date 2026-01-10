#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> per;
        backtrack(nums, per, 0);
        return ans;
    }

    // backtracking with bitmask to track used elements
    void backtrack(vector<int>& nums, vector<int>& per, int mask) {
        if(per.size() == n){
            ans.push_back(per);
            return;
        }

        for(int i=0; i<n; ++i){
            if(mask& (1<<i)) continue; // already used
            per.push_back(nums[i]);
            backtrack(nums, per, mask | (1<<i));
            per.pop_back();
        }
        
    }
};


int main() {
    // test code (optional)
    return 0;
}