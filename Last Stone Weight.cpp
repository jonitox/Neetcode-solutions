#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1) {
            int x = pq.top(); pq.pop(); // get the heaviest stone
            int y = pq.top(); pq.pop(); // get the second heaviest stone
            // if the two heaviest stones are not equal, push the difference back to the priority queue
            // we know x is the heavier one since it's a max heap
            if(x!=y) pq.push(x-y);
        }
        return pq.empty()? 0: pq.top();
    }
};


int main() {
    // test code (optional)
    return 0;
}