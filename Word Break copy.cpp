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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); // dummy head
        ListNode* cur = dummy;
        
        // merge two lists while maintaining sorted order
        while(list1 || list2){
            if(!list1) {
                cur->next = list2;
                list2 = list2->next;
            }
            else if(!list2) {
                cur->next = list1;
                list1 = list1->next;
            }
            else if(list1->val<list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        return dummy->next;

    }
};

int main() {
    // test code (optional)
    return 0;
}