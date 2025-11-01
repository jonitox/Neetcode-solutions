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

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        dfs(root, k, ans);
        return ans;
    }
    
    // inorder traversal
    void dfs(TreeNode* cur, int& k, int& ans){
        if(!cur) return;
        dfs(cur->left, k, ans);
        k--;
        if(k==0){ // found the kth smallest
            ans = cur->val;
            return;
        }
        dfs(cur->right, k, ans);
    }
};

int main() {
    // test code (optional)
    return 0;
}