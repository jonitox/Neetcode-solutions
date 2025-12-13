#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum = 0; // minimum prefix sum encountered so far
        int sum = 0;    // current prefix sum
        int ans = -10000;
        for(int& a: nums){
            sum += a;
            ans = max(ans, sum-minSum); // update the maximum subarray sum
            minSum = min(minSum, sum);
        }
        return ans;
    }
};

int main() {
    // test code (optional)
    return 0;
}