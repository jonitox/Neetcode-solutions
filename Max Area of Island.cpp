#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int ans = 0;
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j){
                // start BFS if cell is land
                if(grid[i][j] == 1){
                    int sz = 1; // size of current island
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 0; // mark as visited
                    while(!q.empty()){
                        int x = q.front().first, y = q.front().second;
                        for(int k=0; k<4; ++k){
                            int nx = x + dx[k], ny = y+ dy[k]; // neighboring cell
                            if(nx <0 || nx >= h || ny<0 || ny >= w) continue;
                            if(grid[nx][ny] == 1) {
                                sz++; 
                                q.push({nx, ny});
                                grid[nx][ny] = 0; // mark as visited
                            }
                        }
                        q.pop();
                    }
                    ans = max(ans, sz); // update max area found
                }
            }
        return ans;
    }
};



int main() {
    // test code (optional)
    return 0;
}