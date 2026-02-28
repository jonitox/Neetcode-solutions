#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sort intervals by their start time
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        // sort queries and keep track of their original indices
        vector<pair<int,int>> qv;
        for (int i = 0; i < queries.size(); ++i) qv.push_back({queries[i], i});
        sort(qv.begin(), qv.end());

        // min-heap to store intervals by their size
        // first = -length of the interval, second = end time of the interval
        priority_queue<pair<int, int>> pq;
        
        int idxI =0;
        vector<int> ans(queries.size(), -1);
        // iterate through the sorted queries
        for(auto [q, i]: qv){
            // add all intervals that start before or at the query point
            // intervals start after the query point cannot contain the query point, so we don't need to consider them
            while(idxI<intervals.size() && intervals[idxI][0]<=q) {
                pq.push({-(intervals[idxI][1]-intervals[idxI][0]+1), intervals[idxI][1]});
                idxI++;
            }
            // remove intervals from the min-heap that end before the query point
            // since those intervals cannot contain the current query point + all query points afterwards
            while(!pq.empty() && pq.top().second < q) pq.pop();
            ans[i]= pq.empty()? -1: -pq.top().first;
        }
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}