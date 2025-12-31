#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size(), w = board[0].size();
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j){
                // start BFS from border 'O's
                if((i == 0 || i == h-1 || j==0 || j == w-1) 
                    && board[i][j]=='O' ){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    board[i][j] = '.'; // mark as visited
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k=0; k<4; ++k){
                            int nx = x + dx[k], ny = y + dy[k];
                            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                            if(board[nx][ny] == 'O') {
                                board[nx][ny] = '.'; // mark as visited
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }

        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j){
                if(board[i][j] == '.') // restore border-connected 'O's
                    board[i][j] = 'O';
                else if (board[i][j] == 'O') // if not connected to border, flip to 'X'
                    board[i][j] = 'X';
            }
    }
};

int main() {
    // test code (optional)
    return 0;
}