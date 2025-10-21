#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans =0;
        while(n){
            n &= n-1; // clear the lowest 1 bit
            ans++;
        }
        return ans;
    }
};


int main() {
    // test code (optional)
    return 0;
}