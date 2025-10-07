#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy; // dummy head
        int o= 0;
        while(o || l1 || l2){
            int v1 = l1? l1->val:0;
            int v2 = l2? l2->val:0;
            int sum = o+v1+v2;
            int a = sum%10; // digit
            o = sum/10; // carry
            cur->next = new ListNode(a);
            cur = cur->next;
            
            l1= l1? l1->next: nullptr;
            l2= l2? l2->next: nullptr;
        }
        return dummy->next;
    }
};

int main() {}