#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0; 
        for(int i=0; i<nums.size(); ++i)
            ans ^= nums[i]; // XOR all numbers, pairs cancel out
        return ans; // the single number remains
    }
};

int main() {
    // test code (optional)
    return 0;
}