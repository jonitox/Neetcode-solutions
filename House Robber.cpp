#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int notRob=0, rob=0; // notRob: max amount if we don't rob current house, rob: max amount if we rob current house
        for(int i=0; i<n; ++i){
            int tmp = max(notRob, rob);
            rob = notRob+nums[i]; // if we rob current house, we can't rob previous one
            notRob = tmp; // if we don't rob current house, take max of previous rob/notRob
        }

        return max(notRob, rob);
    }
};


int main() {
    // test code (optional)
    return 0;
}