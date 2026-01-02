#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int idx = 0;

        // add all intervals ending before newInterval starts
        while(idx < n && intervals[idx][1] < newInterval[0]){ 
            ans.push_back(intervals[idx]);
            idx++;
        }
        
        // merge overlapping intervals
        while(idx < n && intervals[idx][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        ans.push_back(newInterval); // add the merged interval
        
        // add remaining intervals
        while(idx <n) {
            ans.push_back(intervals[idx]);
            idx++;
        }

        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}