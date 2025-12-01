#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum=0; // sum of elements in nums
        for(int i=0; i<n; ++i)
            sum += nums[i];
        return n*(n+1)/2 - sum; // (total sum of 0 to n) - sum of elements in nums
    }
};


int main() {
    // test code (optional)
    return 0;
}