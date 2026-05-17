#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        // binary search approach
        while(l+1<r){
            int mid = (l+r)/2;
            if(target == nums[mid]) return mid;
            else if(target<nums[mid]) r = mid;
            else l = mid; 
        }
        return nums[l]==target? l: -1;
    }
};


int main() {
    // test code (optional)
    return 0;
}