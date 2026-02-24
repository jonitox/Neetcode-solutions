#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sort by start time
        vector<vector<int>> ans;
        vector<int> cand = intervals[0];
        for(int i=1; i< intervals.size(); ++i){
            // if current interval starts after candidate ends, push candidate to ans and update candidate
            if(cand[1] < intervals[i][0]) {
                ans.push_back(cand);
                cand = intervals[i];
            } else{
             cand[1] = max(cand[1], intervals[i][1]); // merge intervals by updating candidate's end time
            }
        }
        ans.push_back(cand);
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}