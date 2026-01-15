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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int cnt = 0; // count total nodes
        while(cur) {
            cur = cur->next;
            cnt++;
        }
        cur = head;
        ListNode* dummy = new ListNode(0, head); 
        ListNode* prev = dummy;
        // move to (cnt-n)th node
        for(int i=0; i<cnt-n; ++i) {
            prev = cur;
            cur = cur->next;
        }
        // cur it is nth node from end, remove it
        prev->next = cur->next;
        return dummy->next;
    }
};

int main() {
    // test code (optional)
    return 0;
}