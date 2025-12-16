#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> ps;
        for(int i=0; i<n; ++i)
            ps.push_back({target-position[i], speed[i]}); // (distance to target, speed)
        sort(ps.begin(), ps.end()); // sort by distance to target
        int d = ps[0].first;
        int s = ps[0].second;
        int ans = 1;
        for(int i=1; i<n; ++i){
            int dd = ps[i].first;
            int ss = ps[i].second;
            if(dd*s > d*ss) { // if the current car cannot catch up to the fleet ahead
                ans++; // form a new fleet
                d = dd; // update the lead car's distance
                s = ss; // update the lead car's speed
            }
        }
        return ans;

    }
};



int main() {
    // test code (optional)
    return 0;
}