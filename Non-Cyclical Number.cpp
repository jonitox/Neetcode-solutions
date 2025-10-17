#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int replace(int n){ // replace n by the sum of the squares of its digits
        int ret =0;
        while(n){
            int d = n%10;
            ret += d*d;
            n /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()){ // detect cycle
            if(n==1) return true;
            s.insert(n);
            n= replace(n);
        }
        return false;
    }
};


int main() {
    // test code (optional)
    return 0;
}