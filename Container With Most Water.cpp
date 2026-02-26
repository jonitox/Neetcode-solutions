#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r= heights.size()-1;
        int ans = 0; 
        while(l<r) {
            int w = r - l; 
            int h = min(heights[l], heights[r]);
            ans = max(ans, w*h);
            // move the shorter line towards the center, since there is no chance to get a larger area with the shorter line
            if(heights[l]< heights[r])
                l++; 
            else
                r--;
        }
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}