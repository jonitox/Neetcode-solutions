#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ensure binary search runs on the smaller array so half - i stays within bounds
        if(nums2.size()< nums1.size()) 
            swap(nums1, nums2);

        int total = nums1.size()+nums2.size();
        int half = (total+1)/2;

        // binary search on smaller array
        int l = 0, r = nums1.size();  
        while(l<=r){
            int i1 = (l+r)/2; // partition index for nums1  (take i1 elements for left part from nums1)
            int i2 = half- i1; // partition index for nums2 (take i2 elements for left part from nums2)
            int left1 = i1>0? nums1[i1-1]: INT_MIN;
            int right1 = i1<nums1.size()? nums1[i1]: INT_MAX;
            int left2 = i2>0? nums2[i2-1] : INT_MIN;
            int right2 = i2<nums2.size()? nums2[i2]: INT_MAX;

            if(left1<=right2 && left2<=right1){ // correct partition found
                return total%2? max(left1, left2) :
                     (max(left1, left2) + min(right1, right2))/2.0;
            }
            else if(left1>=right2) // move partition in nums1 to left
                r = i1-1;
            else // move partition in nums1 to right
                l = i1+1;
        }
    }
};


int main() {
    // test code (optional)
    return 0;
}