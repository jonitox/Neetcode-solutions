#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n);
        for(auto & e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!dfs(0, -1)) return false; // dfs to check cycle
        for(int i=1; i<n; ++i)
            if(!vis[i]) return false; // not connected
        return true; // tree is valid
    }

    bool dfs(int here, int par){
        vis[here] = true;
        for(int there: adj[here]){
            if(there == par) continue;
            if(vis[there]) return false; // cycle detected
            if(!dfs(there, here)) return false;
        }
        return true;
    }
};

int main() {
}