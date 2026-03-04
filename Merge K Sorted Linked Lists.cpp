#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a -> val > b->val;
        };
        // min-heap to store the current nodes of each list, sorted by their value
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // push the head of each list into the min-heap
        for(int i=0; i<lists.size(); ++i){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(!pq.empty()) {
            ListNode* here = pq.top(); // get the node with the smallest value
            pq.pop();
            cur->next = here;
            cur = here;
            // if the current node has a next node in its list, push it into the min-heap
            if(here->next)
                pq.push(here->next);
        }
        return dummy->next;
    }
};


int main() {
    // test code (optional)
    return 0;
}