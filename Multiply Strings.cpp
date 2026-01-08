#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0); // vector to hold the result
        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end());
        for(int i=0; i<num1.size(); ++i){
            for(int j=0; j<num2.size(); ++j){
                int mul = toInt(num1[i])*toInt(num2[j]);
                int idx = i+j;
                ans[idx] += mul; // add multiplication result to the correct position
                ans[idx+1] += ans[idx]/10; // propagate carry to the next digit. Further carry will be handled when that position is processed
                ans[idx] %= 10; // keep only the single digit at current position
            }
        }
        string ret;
        int k = (int)ans.size() - 1;
        while (k > 0 && ans[k] == 0) k--; // skip leading zeros
        for (; k >= 0; --k) 
            ret.push_back(char('0' + ans[k]));
        return ret;
    }
    
    int toInt(char c){
        return c-'0';
    }
};


int main() {
    // test code (optional)
    return 0;
}