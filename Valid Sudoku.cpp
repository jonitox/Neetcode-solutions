#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows
        for(int r=0; r<9; ++r){
            int cnt = 0; // bitmask to track seen numbers
            for(int c=0; c<9; ++c){
                char x = board[r][c];
                if(x == '.') continue;
                if(cnt & 1<<(x-'1')) return false;
                cnt |= 1<<(x-'1');
            }
        }
        // check columns
        for(int c=0; c<9; ++c){
            int cnt = 0;
            for(int r=0; r<9; ++r){
                char x = board[r][c];
                if(x == '.') continue;
                if(cnt & 1<<(x-'1')) return false;
                cnt |= 1<<(x-'1');
            }
        }

        vector<pair<int,int>> v = {
            {0,0}, {0,3}, {0,6},
            {3,0}, {3,3}, {3,6},
            {6,0}, {6,3}, {6,6}
        };

        // check 3x3 sub-boxes  
        for(auto& [r,c]: v){
            int cnt =0;
            for(int i=0; i<3; ++i)
                for(int j=0; j<3; ++j) {
                    char x = board[r+i][c+j];
                    if(x == '.') continue;
                    if(cnt & 1<<(x-'1')) return false;
                    cnt |= 1<<(x-'1');
                }
        }
        return true;
    }
};



int main() {
    // test code (optional)
    return 0;
}