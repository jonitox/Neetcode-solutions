#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int curX= 0, curY=0;
        while(m>=1 && n>=1){
            ans.push_back(matrix[curX][curY]);
            for(int i=0; i<n-1; ++i)
                ans.push_back(matrix[curX][++curY]); // move right
            for(int i=0; i<m-1; ++i)
                ans.push_back(matrix[++curX][curY]); // move down
            for(int i=0; i<n-1 && m>1; ++i)
                ans.push_back(matrix[curX][--curY]); // move left
            for(int i=0; i<m-2 && n>1; ++i)
                ans.push_back(matrix[--curX][curY]); // move up
            m -= 2; n-=2; // reduce the size of the remaining matrix
            curY++;
        }
        return ans;

    }
};


int main() {
    // test code (optional)
    return 0;
}