#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=2; i<n; ++i){
            if(nums[i] < 0) continue;
            if(i < n-1 && nums[i] == nums[i+1]) continue;
            int l =0, r = i-1;
            while(l<r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum <0)
                    l++;
                else if(sum > 0)
                    r--;
                else{
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while(nums[l-1] == nums[l])
                        l++;
                }       
            }
        }
        return ans;
    }
};

int main() {
    // test code (optional)
    return 0;
}