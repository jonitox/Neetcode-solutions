#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int r = grid.size(), c = grid[0].size();
        for(int i=0; i<r; ++i)
            for(int j=0; j<c; ++j)
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++; // found one island
                }

        return ans;
    }

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<char>>& grid){
        grid[x][y]= '0'; // mark as visited
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx< grid.size() && ny >=0 && ny <= grid[0].size() 
             && grid[nx][ny] == '1') // valid and unvisited
                dfs(nx, ny, grid);
        }
    }
};


int main() {
}