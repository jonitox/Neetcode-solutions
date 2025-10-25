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
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
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