#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        vector<bool> dp(n+1,false);
        dp[n] = true;
        
        for(int i=n-1; i>=0; --i){
            for(string& w: wordDict)
                if((i+w.size()-1<n && s.substr(i, w.size()) == w)){ // check if there exists a word that matches s starting at i
                        dp[i] = dp[i] || dp[i+w.size()];
                }
            }
        return dp[0];
    }
};

int main() {
    // test code (optional)
    return 0;
}