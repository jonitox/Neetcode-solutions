#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charCnt(26, 0); // count of each character
        for(char& c :s)
            charCnt[c-'a']++;
        for(char&c : t)
            charCnt[c-'a']--;
        for(int i=0; i<26; ++i)
            if(charCnt[i]) return false;
        return true;
    }
};


int main() {
    // test code (optional)
    return 0;
}