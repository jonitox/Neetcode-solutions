#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> vis = vector<vector<int>>(101, vector<int>(101, -1));
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i=0; i<matrix.size(); ++i)
            for(int j=0; j<matrix[0].size(); ++j)
                if(vis[i][j] == -1)
                    ans = max(ans, dfs(i,j,matrix));

        return ans;
    }

    vector<vector<int>> dir = {
        {0,-1}, {-1,0}, {0,1}, {1,0}
    };

    int dfs(int x, int y, vector<vector<int>>& matrix){
        if(vis[x][y] != -1) return vis[x][y];
        int cnt = 1;
        for(int k=0; k<4; ++k){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            if(nx >=0 && nx <matrix.size() && ny>=0 && ny<matrix[0].size() 
            && matrix[nx][ny] < matrix[x][y])
                cnt = max(cnt, 1+dfs(nx,ny,matrix));
        }
        vis[x][y] = cnt;
        return cnt;
    }
};


int main() {
    // test code (optional)
    return 0;
}