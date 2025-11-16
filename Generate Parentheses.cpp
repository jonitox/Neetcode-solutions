#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        makeParenthesis(s, n, n, ans);
        return ans;
    }

    // backtracking
    // left: number of '(' remaining, right: number of ')' remaining, s: current string, ans: result list
    void makeParenthesis(string& s, int left, int right, vector<string>& ans){
        if(left == 0 && right ==0) {
            ans.push_back(s);
            return;
        }

        if(left>0) {
            s+='(';
            makeParenthesis(s, left-1, right, ans);
            s.pop_back();
        }
        if(right>left && right>0){
            s+=')';
            makeParenthesis(s, left, right-1, ans);
            s.pop_back();
        }
        return;
    }
};


int main() {
    // test code (optional)
    return 0;
}