#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int w, h;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size(), w = board[0].size();
        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(word, i, j, 0, board)) // start DFS if first letter matches
                        return true;
                }
            }

        return false;
    }

    bool dfs(string& word, int x, int y, int idx, vector<vector<char>>& board){
        if(idx == word.size()-1)
            return true;
        board[x][y] = '#'; // mark as visited

        for(int i=0; i<4; ++i){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0 && nx<h && ny>=0 && ny<w 
                && board[nx][ny] == word[idx+1]
                && dfs(word, nx, ny, idx+1, board))
                        return true;
        }
        board[x][y] = word[idx]; // backtrack
        return false;
    }
};



int main() {
    // test code (optional)
    return 0;
}