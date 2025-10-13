#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
        for(auto&c: t){ // count frequency of each character in t
            if(tmap.find(c) == tmap.end()) tmap[c]=1;
            else tmap[c]++;
        }
        int l=0,r=0;
        bool stop;
        for(; r<s.size(); ++r){ // expand the window to the right until it contains all characters of t
            smap[s[r]]++; // count frequency of each character in the current window
            stop = true;
            for(char i='a'; i<='z'; ++i) 
                if(smap[i]<tmap[i]) 
                    stop=false;
            for(char i='A'; i<='Z'; ++i)
                if(smap[i]<tmap[i])
                    stop=false;
            if(stop) break;
        }
        if(r==s.size()) return stop ? s: "";
        string ans = s.substr(l, r-l+1);
        while(r<s.size()){ // slide the window
            while(smap[s[l]]>tmap[s[l]]){ // shrink the window from the left if it still contains all characters of t
                smap[s[l++]]--;
            }
            if(ans.size()>r-l+1) ans= s.substr(l, r-l+1); // update the answer if the current window is smaller
            r++;
            while(r<s.size()&& s[l]!=s[r]){ // expand the window to the right until it contains the character at the left pointer
                smap[s[r++]]++;
            }
            l++;
        }
        return ans;
    }
};


int main() {
}