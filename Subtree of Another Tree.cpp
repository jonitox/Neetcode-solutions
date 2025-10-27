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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }

    bool dfs(TreeNode* here, TreeNode* subRoot){
        if(!here) return false;
        if(sameTree(here, subRoot)) return true;
        return dfs(here->left, subRoot) || dfs(here->right, subRoot); // check left and right subtrees
    }

    bool sameTree(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true; // both are null
        if(root1 && root2 && root1->val == root2->val) // both are non-null and values are equal
            return sameTree(root1->left, root2->left) && 
                sameTree(root1->right, root2->right);
        return false;
    }
};

int main() {
    // test code (optional)
    return 0;
}