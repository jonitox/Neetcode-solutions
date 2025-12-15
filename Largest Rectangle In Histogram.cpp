#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // stack for indices, increasing heights
        int ans =0;
        
        for(int i = 0; i<=heights.size(); ++i){
            while(!st.empty() && (i==heights.size()|| heights[st.top()] >= heights[i])) { //
                int h = heights[st.top()]; // height of the rectangle
                st.pop();
                int w = st.empty()? i: i-st.top()-1; // width of the rectangle
                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}