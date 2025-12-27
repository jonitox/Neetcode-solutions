#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x: s){
            if(s.count(x-1)) continue; // only start counting at the beginning of a sequence
            int cnt = 1;
            int cur = x+1;
            while(s.count(cur++)) // count consecutive numbers
                cnt++;
            ans = max(ans, cnt);
        }

        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}