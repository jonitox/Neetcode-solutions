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
    // fast and slow pointer approach
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow)
                return true;
        }
        return false;    
    }


    /* hash set approach
        bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> vis;
        ListNode* cur = head;

        while(cur){
            vis.insert(cur);
            if(cur->next && vis.count(cur->next))
                return true;
            cur = cur->next;
        }
        return false;    
    }
    */
};




int main() {
    // test code (optional)
    return 0;
}