#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l =0, r =n-1;
        // binary search approach, minimum is where the order breaks
        while(l<r){
            if(nums[l] < nums[r]) { // ascending order, minimum is at l
                return nums[l];
            }
            int mid = (l+r)/2;
            if(nums[l]<=nums[mid]) { // left half is sorted, minimum is in right half
                l = mid+1;
            } else // right half is sorted, minimum is in left half
                r = mid;
        }
        return nums[l];
    
    }
};


int main() {
    // test code (optional)
    return 0;
}