#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int sellMax1=0, sellMax2 = 0; // sellMax1: max profit after selling stock, sellMax2: max sellMax1 till i-2th day
        int buyMax = -prices[0]; // max profit after buying stock
        for(int i=1; i<n; ++i){
            int tmp = sellMax1;
            sellMax1 = max(sellMax1, prices[i] + buyMax); // sell stock today
            buyMax = max(buyMax, sellMax2 - prices[i]); // buy stock after cooldown
            sellMax2 = tmp;
        }
        return sellMax1;
    }
};

    }
};

int main() {
    // test code (optional)
    return 0;
}