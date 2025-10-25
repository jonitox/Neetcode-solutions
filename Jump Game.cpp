#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size();
       int l = 0, r = 0;
       while(r<n-1){
            int nextr= 0;
            for(int i=l; i<=r; ++i)
                nextr = max(nextr, i+nums[i]); // furthest we can reach from [l, r]
            if(nextr <= r) return false;
            l = r+1; r= nextr;  // update the window [l, r]
       }
       return true;
    }
};


int main() {
    // test code (optional)
    return 0;
}