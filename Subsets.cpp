#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bit manipulation approach
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i =0; i<(1<<nums.size()); ++i){
            vector<int> sub;
            for(int j=0; j<nums.size(); ++j){
                if(i& (1<<j))
                    sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }

    /* backtracking approach

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        makeSubset(nums, 0, sub, ans);
        return ans;
    }
    void makeSubset(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& ans) {
        if(index==nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[index]);
        makeSubset(nums, index+1, sub, ans);

        sub.pop_back();
        makeSubset(nums, index+1, sub, ans);
        return;
    }
    */
};


int main() {
    // test code (optional)
    return 0;
}