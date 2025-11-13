#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Solution {
public:
    int countSubstrings(string s) {
        int ans =0;
        for(int i=0; i<s.size(); ++i){
            int l = i, r=i; // center at i
            while(0<=l && r<s.size() && s[l--] == s[r++]){ // odd-length palindromes
                ans++;
            }
            l = i; r=i+1;  // center between i and i+1
            while(0<=l && r<s.size() && s[l--] == s[r++]){ // even-length palindromes
                ans++;
            }
        }
        return ans;
    }
};


    // check if two words differ by exactly one letter
    bool isAdjacent(string& a, string& b){
        int cnt = 0;
        for(int i=0; i < a.length(); ++i){
            if(a[i] != b[i]) cnt++;
        }
        return cnt==1;
    }
};

int main() {
    // test code (optional)
    return 0;
}