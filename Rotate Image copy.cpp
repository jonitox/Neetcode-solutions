#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int ans = -INT_MAX;

        // since negative * negative = positive, 
        // subarray with max product must appear as either a prefix of some segment or a suffix of some segment
        // But when encounter 0, product resets

        // left to right(prefix)
        int prod = 1;
        for(int i=0; i<n; ++i) {
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) // reset when encounter 0
                prod = 1;
        }

        // right to left(suffix)
        prod = 1;
        for(int i=n-1; i>=0; --i){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) // reset when encounter 0
                prod = 1;
        }
        return ans;
    }
};





int main() {
    // test code (optional)
    return 0;
}