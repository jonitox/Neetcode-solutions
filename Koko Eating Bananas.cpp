#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for(int& p: piles)
            m = max(p, m);
        int lo = 0, hi = m;
        while(lo+1<hi){ // binary search for the minimum rate that allows Koko to finish in h hours
            int mid = (lo+hi)/2;
            int time = 0;
            for(int&p : piles)
                time += (p-1)/mid +1; // hours needed for pile p at speed mid
            if(time > h)
                lo = mid; 
            else
                hi = mid; 
        }
        return hi;
    }
};

int main() {
    // test code (optional)
    return 0;
}