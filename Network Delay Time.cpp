#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1000000000;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1, INF);
        vector<vector<pair<int,int>>> adj(n+1); // adjacency list
        for(auto& t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        // Run Dijkstra
        priority_queue<pair<int,int>> pq;
        pq.push({0, k});
        dis[k]=0;

        while(!pq.empty()){
            int here = pq.top().second;
            int d = -pq.top().first;
            pq.pop();
            if(dis[here] < d) continue;
            for(auto& e: adj[here]){
                int there = e.first;
                int w = e.second;
                if(dis[there] > d+w){
                    dis[there] = d+w;
                    pq.push({-(d+w), there});
                }
            }
        }
        int ans =0;
        for(int i=1; i<=n; ++i){
            ans = max(ans, dis[i]); // longest time to reach any node
        }
        return ans==INF?-1:ans; // if any node is unreachable, return -1
    }
};


int main() {
    // test code (optional)
    return 0;
}