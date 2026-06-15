#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=1, r = n-2;
        int leftMax = height[0], rightMax = height[n-1];
        int res = 0;
        // the water trapped in ith tile = min(leftMax, rightMax) - height[i], where leftMax = maxHeight in [0,i), rightMax = maxHeight in (i,n-1]
        while(l<=r){
            // if leftMax in [0, l-1] < rightMax in [r+1, n-1], we can decide watter trapped in lth tile. 
            if(leftMax<rightMax) {
                leftMax = max(leftMax, height[l]); // max first, for handling the case where leftMax in [0, l-1] <= height[l].
                res += leftMax - height[l];
                l++;
            } else{ 
                // if leftMax in [0, l-1] >= rightMax in [r+1, n-1], we can decide watter trapped in rth tile. 
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
                r--;
            }
        }
        return res;
    }
};


int main() {
    // test code (optional)
    return 0;
}