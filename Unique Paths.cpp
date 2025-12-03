#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* dp approach
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; ++i)
            dp[i][0] = 1;
        for(int j=0; j<n; ++j)
            dp[0][j] = 1;    
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
    */
    
    // math approach
    int uniquePaths(int m, int n) {
        int ret = 1;
        if(m==1 || n==1)
            return 1;
        m--; n--;
        int j=1;
        for(int i=m+n; i>m; --i){ // compute (m+n)! / (m! * n!)
            ret *= i;
            ret /= j++; // it's safe since ret is divisible by j at each step
        }
        return ret;
    }

};


int main() {
    // test code (optional)
    return 0;
}