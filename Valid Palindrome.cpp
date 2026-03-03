#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss=""; // ss will store the alphanumeric characters in lowercase
        for(char c: s){
            if('a'<=c && c<='z') ss += c;
            else if('0'<=c && c<='9') ss += c;
            else if('A'<=c && c<='Z') ss += c-'A'+'a';
            else continue;
        }
        string orig = ss;
        reverse(ss.begin(),ss.end());
        return orig == ss; // check if the string is the same as its reverse
    }
};



int main() {
    // test code (optional)
    return 0;
}