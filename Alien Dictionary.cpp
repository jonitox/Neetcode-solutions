#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> adj =  vector<vector<bool>>(26, vector<bool>(26, false));
    vector<int> inDeg = vector<int>(26,0);
    string foreignDictionary(vector<string>& words) {
        // consider only alphabets that exist in words
        vector<bool> seen(26,false);
        int cntSeen=0;
        for(string& s: words){
            for(char&c : s){
                if(!seen[c-'a']){
                    seen[c-'a'] = true;
                    cntSeen++;
                }
            }
        }

        // make graph. add an edge (x->y) if alphablet x is lexicographically smaller than y
        for (int i = 0; i < words.size()-1; ++i) {
            string& s1 = words[i];
            string& s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int k = 0;
            for (; k < len; ++k) {
                if (s1[k] != s2[k]) {
                    int u = s1[k] - 'a';
                    int v = s2[k] - 'a';
                    if (!adj[u][v]) {
                        adj[u][v] = true;
                        inDeg[v]++;
                    }
                    break;
                }
            }
            // Invalid if s2 is prefix of s1. This should be checked here.
            if (k == len && s1.size() > s2.size()) return "";
        }

        // topological sort. consider only alphabets that exist in words.
        queue<int> q;
        for(int i=0; i<26; ++i){
            if(seen[i] && inDeg[i]==0)
                q.push(i);
        }
        string ans = "";
        while(!q.empty()){
            int here = q.front();
            q.pop();
            ans += 'a' + here;
            for(int i=0; i<26; ++i){
                if(i==here) continue;
                if(adj[here][i]) {
                    adj[here][i] = false;
                    inDeg[i]--;
                    if(inDeg[i] ==0) 
                        q.push(i);
                }
            }
        }
        
        return ans.size() == cntSeen ? ans: "";
    }

};


int main() {
    // test code (optional)
    return 0;
}