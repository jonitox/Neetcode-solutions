#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> m; // map from key to list of (timestamp, value) pairs
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it == m.end()) return ""; // key not found

        auto& v = it->second;
        // binary search to find the upper bound of the given timestamp
        auto ub = upper_bound(v.begin(), v.end(),timestamp, 
            [](int t, const pair<int,string>& p) {
                return t < p.first;
            }
        );

        if (ub == v.begin()) return ""; // all timestamps are greater than the given timestamp
        return prev(ub)->second; // return value at largest timestamp <= given timestamp
    }
};


int main() {
    // test code (optional)
    return 0;
}