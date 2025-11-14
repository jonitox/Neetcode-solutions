#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); // dp[i][j]: length of LCS of text1[0..i-1] and text2[0..j-1]
        for(int i=1; i<=n1; ++i)
            for(int j=1; j<=n2; ++j){
                dp[i][j] = max(
                    text1[i-1] == text2[j-1]? dp[i-1][j-1]+1 : dp[i-1][j-1], // the last characters match
                    max(dp[i-1][j], dp[i][j-1]) // skip one character from either text1 or text2
                );
            }
        return dp[n1][n2];
    }
};


int main() {
    // test code (optional)
    return 0;
}