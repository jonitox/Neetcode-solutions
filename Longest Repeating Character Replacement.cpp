#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        for(int i=0; i<26; ++i){
            char c = 'A'+i;
            // sliding window approach
            int l = 0, bad =0; // bad: count of chars not equal to c in current window
            for(int r=0; r<s.size(); ++r){
                if(s[r]!=c) bad++;
                while(bad >k) {
                    if(s[l++] != c) bad--;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};



int main() {
    // test code (optional)
    return 0;
}