#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;    // {temperature, index}, monotonically decreasing stack
        vector<int> ret(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); ++i){
            int t = temperatures[i];
            while(!st.empty() && st.top().first < t){   // found a first warmer temperature for st.top().
                int idx = st.top().second;
                ret[idx] = i - idx;
                st.pop();
            }
            st.push({t,i});
        }       
        return ret; 
    }
};


int main() {
    // test code (optional)
    return 0;
}