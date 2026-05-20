#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BST(map) approach, O(N*logK)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     map<int,int> m;
    //     vector<int> ret;
    //     for(int i=0; i<nums.size(); ++i){
    //         m[nums[i]]++;
    //         if(i<k-1) continue;
    //         ret.push_back(m.rbegin()->first);
    //         if(--m[nums[i-k+1]] == 0)
    //             m.erase(nums[i-k+1]);
    //     }
    //     return ret;
    // }

    // deque approache, O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // A monotonic deque of increasing indices with values in decreasing order.
        vector<int> ret;
        for(int i=0; i<nums.size(); ++i) {
            // Drop index if it's outside the window. No need to use a while loop since 'i' always increases by 1.
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Drop indices from the back if their values are smaller.
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back(); 
            } 
            
            dq.push_back(i);

            if (i >= k - 1) {
                ret.push_back(nums[dq.front()]); // Front element is always the max of the window.
            }
        }
        return ret;
    }
};
 


int main() {
    // test code (optional)
    return 0;
}