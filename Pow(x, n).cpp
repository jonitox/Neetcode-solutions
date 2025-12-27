#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;   
        if (nn < 0) { // handle negative exponent
            x = 1 / x;
            nn = -nn;
        }

        double result = 1.0;
        while (nn > 0) {
            if (nn & 1) result *= x;
            nn >>= 1; // handle next bit of exponent
            x *= x; // square the base (x^(2^i) for next bit)
        }
        return result;
    }
};


int main() {
    // test code (optional)
    return 0;
}