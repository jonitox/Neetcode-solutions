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
    
    // O(n) time, O(k) space
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode* cur = head;
    //     ListNode* dummy = new ListNode();
    //     ListNode* prevLast = dummy;
    //     while(cur){
    //         vector<ListNode*> v;
    //         for(int i=0; i<k; ++i){ // collect k nodes
    //             if(!cur) break;
    //             v.push_back(cur);
    //             cur = cur->next;
    //         }
    //         if(v.size()<k){ // less than k nodes left, attach as is
    //             prevLast->next = v[0];
    //             break;
    //         }
    //         prevLast->next = v[k-1]; // link previous part to the new first node
    //         for(int i=k-1; i>=1; --i){ // reverse links
    //             v[i]->next = v[i-1];
    //         }
    //         v[0]->next = nullptr;
    //         prevLast = v[0]; // update prevLast to the last node in the reversed group
    //     }
    //     return dummy->next;
    // }

    // O(n) time, O(1) space
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevLast = dummy;
        while(true){
            ListNode* kth = prevLast; 
            for(int i=0; i<k && kth; ++i) // // find the kth node for the current group
                kth = kth->next;
            if(!kth) break;

            ListNode* curr = prevLast->next;
            ListNode* prev = kth->next;
            ListNode* nextFirst = kth->next;
            while(curr != nextFirst){   // reverse k nodes
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            curr = prevLast->next; // curr is now the last node in the reversed group
            prevLast->next = kth; // link previous part to the new first node
            prevLast = curr; // update prevLast
        }
        return dummy->next;
    }
};



int main() {
    // test code (optional)
    return 0;
}