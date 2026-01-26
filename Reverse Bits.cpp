#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i=0; i<32; ++i){
            ret <<= 1;  // shift ret to left to make space for the next bit
            ret += (n>>i)&1; // get the i-th bit from n and add to ret
        }
        return ret;
    }
};


int main() {
}