#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int lo= 0, hi= m;
        while(lo+1<hi){ // binary search to find the row
            int mid = (lo+hi)/2;
            if(matrix[mid][0] < target)
                lo = mid;
            else if(matrix[mid][0] > target)
                hi = mid;
            else
                return true;
        }
        int row = lo;
        lo = 0, hi = n;
        while(lo+1<hi){ // binary search in the row
            int mid = (lo+hi)/2;
            if(matrix[row][mid] < target)
                lo = mid; 
            else if(matrix[row][mid] > target)
                hi = mid;
            else
                return true;
        }
        return matrix[row][lo] == target;
    }
};


int main() {
    // test code (optional)
    return 0;
}