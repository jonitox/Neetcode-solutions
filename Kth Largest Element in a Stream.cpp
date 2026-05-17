#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // minHeap containing K largest elements
    int kk;
    KthLargest(int k, vector<int>& nums) {
        for(int&a: nums){
            minHeap.push(a);
            if(minHeap.size()>k){
                minHeap.pop(); // drop top(min) of Heap if size > k 
            }
        }
        kk = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kk){
                minHeap.pop(); // drop top(min) of Heap if 
        }
        return minHeap.top();
    }
};


int main() {
    // test code (optional)
    return 0;
}