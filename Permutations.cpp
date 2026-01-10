#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> per;
        bruteForce(nums, per, 0);
        return ans;
    }

    void bruteForce(vector<int>& nums, vector<int>& per, int mask) {
        if(per.size() == n){
            ans.push_back(per);
            return;
        }

        for(int i=0; i<n; ++i){
            if(mask& (1<<i)) continue;
            per.push_back(nums[i]);
            bruteForce(nums, per, mask | (1<<i));
            per.pop_back();
        }
        
    }
};


int main() {
    // test code (optional)
    return 0;
}