#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> digitToChars = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    }; 
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        backTrack(0, digits, "");
        return ans;
    }

    // Backtracking appraoch
    void backTrack(int i, string digits, string letters){
        if(i==digits.size()) {
            ans.push_back(letters);
            return;
        }
        string letterCand = digitToChars[digits[i]-'0'-2]; // get candidate letters for current digit
        for(char c: letterCand) {
            backTrack(i+1, digits, letters+c);
        }
        return;
    }
};


int main() {
    // test code (optional)
    return 0;
}