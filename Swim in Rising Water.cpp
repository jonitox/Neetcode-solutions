#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int,int>>> pq; // heap to store (time, (x,y)). we use negative time for min-heap
        vector<bool> vis(n*n);
        pq.push({-grid[0][0],{0,0}}); // start from (0,0) at time grid[0][0]

        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
        // Dijkstra's algorithm, it will always expand the least time node first
        while(!pq.empty()){
            int time = -pq.top().first;
            auto [x , y] = pq.top().second;
            pq.pop();
            if (vis[x*n+y]) continue;
            vis[x*n+y] = true;

            if(x == n-1 && y == n-1)
                return time;
            for(int d =0; d<4; ++d){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx >=0 && nx < n && ny >= 0 && ny < n && !vis[nx*n+ny])
                    pq.push({-max(time, grid[nx][ny]), {nx, ny}}); // push neighbor with time updated to max of current time and neighbor's elevation
            }
            
        }    
        return 0;
    }


};


int main() {
    // test code (optional)
    return 0;
}