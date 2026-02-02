#include <bits/stdc++.h>
using namespace std;

class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt; // cnt[x][y] = number of points at (x, y)

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for (auto& [y, ptCnt] : cnt[px]) { // iterate over all points with same x-coordinate
            int len = abs(y - py); 
            if(len==0) continue; // skip same poin
            
            // squre {px, py}, {x, py}, {px,y}, {x, y} where x = px + (y-py)
            int x = px + len; 
            res += ptCnt * cnt[x][py] * cnt[x][y];
            // squre {px, py}, {x, py}, {px,y}, {x, y} where x = px - (y-py)
            x = px - len;
            res += ptCnt * cnt[x][py] * cnt[x][y];
        }
        return res;
    }
};


int main() {
}