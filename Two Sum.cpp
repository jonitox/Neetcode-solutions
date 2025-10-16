#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> sorted;
        for(int i=0; i<n; ++i){
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(), sorted.end()); // sort by value
        int l = 0, r=n-1;
        while(l<r){ // two pointers
            int sum = sorted[l].first+sorted[r].first;
            if(sum==target){
                int lidx = sorted[l].second, ridx = sorted[r].second;
                if(lidx>ridx) swap(lidx,ridx);
                return vector<int>{lidx,ridx};
                }
            if(sum<target)
                l++;
            if(sum>target)
                r--;
        }
    }
};



int main() {
    // test code (optional)
    return 0;
}