#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int INF = 2147483647;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();    
        
        queue<pair<int,int>> q;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j] ==0)
                    q.push({i,j});

        while(!q.empty()){ // BFS with multiple sources
            pair<int,int> here = q.front();
            q.pop();
            for(int i=0; i<4; ++i)
                for(int j=0; j<4; ++j){
                    pair<int,int> there = {here.first + dx[i], here.second +dy[i]}; // neighboring cell
                    if(there.first<0 || there.first>=m) continue;
                    if(there.second<0 || there.second>=n) continue;
                    if(grid[there.first][there.second] == INF) { // unvisited land cell
                        grid[there.first][there.second] = grid[here.first][here.second]+1;
                        q.push(there);
                    }
                }
        }
    }
};



int main() {
    // test code (optional)
    return 0;
}