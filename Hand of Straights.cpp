#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;  
        multiset<int> ms(hand.begin(), hand.end());

        while (!ms.empty()) {
            int start = *ms.begin(); // smallest card
            for (int x = start; x < start + groupSize; ++x) { // try to form a group from start to start + groupSize - 1
                auto it = ms.find(x);
                if (it == ms.end()) return false;
                ms.erase(it);  
            }
        }
        return true;
    }
};


int main() {
    // test code (optional)
    return 0;
}