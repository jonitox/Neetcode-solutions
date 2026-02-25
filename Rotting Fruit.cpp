#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>> q;
        int fresh =0; // count of fresh oranges
        for(int i=0; i<r; ++i) 
            for(int j=0; j<c; ++j)
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;

        vector<vector<int>> dir = {
            {0,-1}, {-1,0}, {0,1}, {1,0}
        };
        // BFS approach
        int minutes = 0;
        while(!q.empty() && fresh >0){ // if there are still fresh oranges and queue is not empty
            int qsize = q.size();
            for(int i=0; i<qsize; ++i) {
                auto [x,y] = q.front();
                q.pop();
                for(int k =0; k<4; ++k){
                    int nx = x+dir[k][0], ny = y+dir[k][1];
                    if(nx<r && nx>=0 && ny<c && ny>=0 && grid[nx][ny]==1){
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        fresh--;
                    }
                }

            }
            minutes++; // increment minutes after each level of BFS
        }
        return fresh == 0? minutes: -1;
        
    }
};


int main() {
    // test code (optional)
    return 0;
}