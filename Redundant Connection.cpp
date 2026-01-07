#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* topological sort approach
    vector<vector<int>> adj;
    vector<int> deg;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n+1); deg.resize(n+1);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        // remove leaf nodes iteratively
        queue<int> q;
        for(int i=1; i<=n; ++i)
            if(deg[i]==1)
                q.push(i);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(--deg[v]==1)
                    q.push(v);
            }
        }
        vector<int> ret;
        for(auto& e: edges){
            if(deg[e[0]]==2 && deg[e[1]] ==2) // degree 2 means it's in the cycle
                ret = e;
        }
        return ret;
    }
    */

    // union-find approach
    vector<int> parent; 
    vector<int> rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) { 
        int n = edges.size(); 
        parent.resize(n+1); 
        rank.resize(n+1); 
        for(int i=1; i<=n; ++i){ 
            parent[i] = i; 
            rank[i] = 1; 
        } 
        for(auto& e: edges){ 
            // if they are already in the same set, this edge creates a cycle and is redundant 
            // Also, it must be the last such edge in the input order
            if(!merge(e[0], e[1])) 
                return {e[0], e[1]};
        } 
    }
    
    int find(int u){ 
        if(u == parent[u]) return u; 
        return parent[u] = find(parent[u]); 
    } 
    
    bool merge(int u, int v){ 
        u = find(u); v= find(v); 
        if(u==v) return false; 
        if(rank[u] > rank[v]) swap(u,v); 
        parent[u] = v; 
        if(rank[u] == rank[v]) ++rank[v]; 
        return true; 
    } 

};



int main() {
    // test code (optional)
    return 0;
}