#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2= t.size();
        vector<vector<int>> dp(2, vector<int>(n2+1,0)); // dp[i%2][j] = number of ways to form the first j chars of t using the first i chars of s
        dp[0][0] =1;
        for(int i=1; i<=n1; ++i){
            dp[i%2][0] = 1;
            for(int j=1; j<=n2;++j){
                dp[i%2][j] = dp[(i-1)%2][j];
                if(s[i-1] == t[j-1])
                    dp[i%2][j] += dp[(i-1)%2][j-1]; 
            }
        }

        return dp[n1%2][n2];
    }
};


int main() {
    // test code (optional)
    return 0;
}