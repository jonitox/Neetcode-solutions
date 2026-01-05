#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* dp bottom-up approach
    vector<vector<string>> partition(string s) {
                int n = s.size();
        vector<vector<vector<string>>> dp(n + 1); // dp[i]: all palindrome partitions of s[i..n-1]
        dp[n] = {{}};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (isPal(s, i, j)) {
                    string sub = s.substr(i, j - i + 1);
                    for (auto& arr : dp[j + 1]) {
                        auto tmp = arr;
                        tmp.insert(tmp.begin(), sub);
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        return dp[0];
    }
    */

    // dfs + backtracking approach
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> subs;
        dfs(0, s, subs, ans);
        return ans;
    }

private:
    void dfs(int i, string& s, vector<string>& subs, vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(subs);
            return;
        }

        for(int j=i; j<s.size(); ++j){
            if(isPal(s, i,j)){
                subs.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, subs, ans); // explore further after adding current palindrome substring
                subs.pop_back();
            }
        }
    }
    bool isPal(string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
};



int main() {
    // test code (optional)
    return 0;
}