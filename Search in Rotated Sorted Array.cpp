#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l = 0, r=n; // search in [l, r)
        if(nums.front() == target) return 0;
        while(l+1<r){ // binary search
            int mid = (l+r)/2;
            if(nums.front()<target){
                if(nums.front()>nums[mid] || target< nums[mid]) // target is in the left half
                    r = mid;
                else
                    l = mid; 
            }
            else{ // target < nums.front()
                if(nums.front() < nums[mid] || target >= nums[mid]) // target is in the right half
                    l = mid; 
                else
                    r = mid;
            }
        }
        return nums[l] == target? l : -1;
    }
};


int main() {
    // test code (optional)
    return 0;
}