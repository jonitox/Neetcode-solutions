#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; // both are null
        if(!p || !q) return false; // one of them is null
        return (p->val == q->val) // values are equal
        && isSameTree(p->left, q->left) // left subtrees are equal
        && isSameTree(p->right, q->right); // right subtrees are equal
    }
};


int main() {
    // test code (optional)
    return 0;
}