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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        vector<ListNode*> v;

        while(cur != nullptr){
            v.push_back(cur);
            cur = cur->next;
        }

        int l=0, r=v.size()-1;

        while(l+1<r){ // reorder by connecting nodes from both ends
            v[l]->next=v[r];
            v[r]->next=v[l+1];
            l++; r--;
        }
        if(l==r)  // odd number of nodes, l is the last node
            v[l]->next = nullptr;
        else     // even number of nodes, r is the last node
            v[r]->next = nullptr;
    }


    // void reorderList(ListNode* head) {
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;
    //     while (fast != nullptr && fast->next != nullptr) { // find the middle using slow and fast pointers
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }

    //     ListNode* second = slow->next;
    //     ListNode* prev = slow->next = nullptr;
    //     while (second != nullptr) {  // reverse the second half
    //         ListNode* tmp = second->next;
    //         second->next = prev;
    //         prev = second;
    //         second = tmp;
    //     }

    //     ListNode* first = head;
    //     second = prev;
    //     while (second != nullptr) {  // merge two halves
    //         ListNode* tmp1 = first->next;
    //         ListNode* tmp2 = second->next;
    //         first->next = second;
    //         second->next = tmp1;
    //         first = tmp1;
    //         second = tmp2;
    //     }
    // }
};




int main() {
    // test code (optional)
    return 0;
}