#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0; i < (n+1)/2; ++i)
            for(int j=0; j<n/2; ++j){ // rotate 4 elements
                int a1 = matrix[i][j], 
                    a2 = matrix[j][n-1-i], 
                    a3 = matrix[n-1-i][n-1-j], 
                    a4 = matrix[n-1-j][i];
                matrix[i][j] = a4;
                matrix[j][n-1-i] = a1;
                matrix[n-1-i][n-1-j] = a2;
                matrix[n-1-j][i]=a3;
            }
        return;
    }

    // void rotate(vector<vector<int>>& matrix) {
    //     // Reverse the matrix vertically
    //     reverse(matrix.begin(), matrix.end());

    //     // Transpose the matrix
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }

    
};




int main() {
    // test code (optional)
    return 0;
}