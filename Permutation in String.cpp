#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0), count2(26,0);
        for(int i=0; i<s1.size(); ++i){
            count[s1[i]-'a']++; // count frequency of each character in s1
        }

        for(int i=0; i<s2.size(); ++i){
            if(i>=s1.size())
                count2[s2[i-s1.size()]-'a']--;  // remove the character going out of the window
            count2[s2[i]-'a']++;          // add the character coming into the window
            bool flag=true;
            for(int j=0; j<26; ++j)
                if(count[j] != count2[j])   // compare frequency of characters in window
                    flag=false;
            if(flag)
                return true;
        }
        return false;            
    }
};


int main() {
    // test code (optional)
    return 0;
}