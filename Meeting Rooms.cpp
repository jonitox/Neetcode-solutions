#include <bits/stdc++.h>
using namespace std;

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;  // sort by start time
        });
        for(int i=1; i<intervals.size(); ++i)
            if(intervals[i-1].end >intervals[i].start) // overlap
                return false;
        return true;
    }
};



int main() {
    // test code (optional)
    return 0;
}