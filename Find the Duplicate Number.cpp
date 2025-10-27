#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s; // set to track seen numbers
        for(int& n: nums){
            if(s.find(n) == s.end())
                s.insert(n);
            else
                return n;
        }
    }

    /* Fast and Slow Pointer
    int findDuplicate(vector<int>& nums) { 
        int slow = 0, fast = 0;
        // Phase1: detect cycle(duplicate number)
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        } 
        // When they meet,
        // Let L = distance from start to cycle start (entrance)
        // Let C = length of cycle
        // Let X = distance from cycle start to meeting point
        // Then, we have: 2(L + X) = L + X + nC  =>  L = nC - X

        int slow2 = 0;
        // Phase2: find the entrance(duplicate number)
        // slow is inside the cycle (distance C - X from entrance of cycle).
        // Since L = nC - X, after L steps, slow2 (from start) and slow (in cycle) will meet at the entrance.
        while (true) { 
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
    */
};





int main() {
    // test code (optional)
    return 0;
}