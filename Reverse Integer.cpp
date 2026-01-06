#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ret =0;
        bool neg = x < 0;
        x = abs(x);
        while(x){
            // extract last digit of x and append to ret
            ret*=10;
            ret += x%10;  
            x /= 10;
            if(ret > INT_MAX || ret < INT_MIN) // check for overflow
                return 0;
        }
        return neg? -ret: ret;
    }
};

int main() {
    // test code (optional)
    return 0;
}