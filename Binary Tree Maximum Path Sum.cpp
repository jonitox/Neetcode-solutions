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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

    // dfs approach, O(V)
    // Returns the maximum sum of a single path starting from the current node and moving downwards.
    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int left = max(dfs(root->left, ans), 0); // Ignore negative paths by taking max with 0
        int right = max(dfs(root->right, ans), 0);
        
        ans = max(ans, left+right+root->val); // Update global maximum using the current node as the highest point
        return root->val + max(left, right); // Return the maximum single-branch path sum
    }
};

int main() {
    // test code (optional)
    return 0;
}