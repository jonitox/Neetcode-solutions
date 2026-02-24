#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    // DP approach, time: O(n^2), space: O(n^2)
    string longestPalindrome(string s) {
        int len = s.size();
        string ret = s.substr(0,1);
        int longest = 1;
        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int i=0; i<len; ++i)
            dp[i][i] = true;
        for(int i = len-1; i>=0; --i)
            for(int j=i+1; j<len; ++j){
                if(s[i]!=s[j]) continue;
                dp[i][j] = (j == i+1) ? true : dp[i+1][j-1];
                
                if(dp[i][j] && longest < j-i+1){
                    longest = j-i+1;
                    ret = s.substr(i, j-i+1);
                }
            }
        return ret;
    }
    */

    // Two pointer approach, time: O(n^2), space: O(1)
    string longestPalindrome(string s) {
        int resLen = 0, resIdx = 0;

        // Expand arround center
        for (int i = 0; i < s.size(); i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};


int main() {
    // test code (optional)
    return 0;
}