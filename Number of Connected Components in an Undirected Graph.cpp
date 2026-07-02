#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int u) {
        if(u==par[u]) return u;
        return par[u] = find(par[u]);
    }
    void merge(int u, int v) {
        u= find(u); v = find(v);
        if(u==v) return;
        if(rank[u] > rank[v]) swap(u,v);
        par[u]= v;
        if(rank[u] == rank[v]) rank[v]++;
    }

    // Disjoint Set Union approach
    int countComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        rank.resize(n);
        for(int i=0; i<n; ++i){
            par[i] = i;
            rank[i]=1;
        }
        int ans = n;
        for(vector<int>& v: edges){
            int a= v[0], b = v[1];
            // everytime sets can be merged, # of sets decrease -1
            if(find(a) != find(b)){
                merge(a,b);
                ans--;
            }
        }
        return ans;

    }
};



int main() {
    // test code (optional)
    return 0;
}