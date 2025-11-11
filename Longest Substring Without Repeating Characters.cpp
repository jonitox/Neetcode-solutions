#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> have(128, false);
        if(s.empty()) return 0;
        int l =0, r=0, ans =1;
        have[(int)s[0]]=true;
        // sliding window
        while(r<s.size()){
            ans = max(ans, r-l+1);
            if(have[(int)s[r+1]]) // s[r+1] is duplicate, move l to the right
                have[(int)s[l++]] = false;
            else
                have[(int)s[++r]] = true;
        }
        return ans;
    }
};

int main() {
    // test code (optional)
    return 0;
}