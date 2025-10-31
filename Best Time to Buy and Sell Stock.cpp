#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int m =prices.back(); // max price from the right
        for(int i=prices.size()-2; i>=0; --i){
            ans = max(ans, m-prices[i]); // sell at m, buy at prices[i]
            m = max(m, prices[i]);
        }
        return ans; 
    }
};

int main() {
    // test code (optional)
    return 0;
}


