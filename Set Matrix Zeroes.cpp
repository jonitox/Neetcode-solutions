#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        bool firstRow = false, firstCol = false; // flags for first row and first column
        for(int i=0; i<r; ++i)
            for(int j=0; j<c; ++j){
                if(matrix[i][j] == 0){
                    if(i==0) 
                        firstRow = true;
                    else
                        matrix[i][0] = 0; // mark the first cell of the row
                    if(j==0)
                        firstCol = true;
                    else
                        matrix[0][j] = 0; // mark the first cell of the column
                }
            }

        for(int i=1; i<r; ++i)
            for(int j=1; j<c; ++j)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0; // set cell to zero if its row or column is marked
        
        if(firstRow)
            for(int j=0; j<c; ++j)
                matrix[0][j] = 0; // set first row to zero
        if(firstCol)
            for(int i=0; i<r; ++i)
                matrix[i][0] = 0; // set first column to zero
    }
};


int main() {
    // test code (optional)
    return 0;
}