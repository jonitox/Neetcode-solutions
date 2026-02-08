#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l= 0, r=numbers.size()-1;
        int sum;
        // two pointers approach
        while(l<r) {
            sum = numbers[l] + numbers[r];
            if(sum == target)
                return {l+1, r+1};
            if(sum < target)    // need a larger sum
                l++;
            else    // need a smaller sum
                r--;
        }
        return {};
    }
};



int main() {
    // test code (optional)
    return 0;
}