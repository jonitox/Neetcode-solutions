#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int& n: nums){
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop(); // keep only k largest elements in the min-heap
        }
        return minHeap.top();
    }
};


int main() {
    // test code (optional)
    return 0;
}