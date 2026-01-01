#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> arr;
        backTracking(0, nums, arr, ans);
        
        return ans;
    }

    void backTracking(int pos, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans) {
        if(pos == nums.size()){
            ans.push_back(arr);
            return;
        }
        int num = nums[pos];
        int cnt = 0; // count duplicates of nums[pos]
        while(pos < nums.size() && num == nums[pos]){
            cnt++;
            pos++; // move to next different number
        }

        backTracking(pos, nums, arr, ans); // not include current number
        for(int i=1; i<=cnt; ++i){ // include current number i times
            arr.push_back(num);
            backTracking(pos, nums, arr, ans);
        }

        for(int i=1; i<=cnt; ++i)
            arr.pop_back(); // backtrack

        return;
    }
};



int main() {
    // test code (optional)
    return 0;
}