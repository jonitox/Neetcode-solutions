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
    bool isValidBST(TreeNode* root) {
        int INF = 10000;
        return dfs(root, -INF, INF);
    }

    bool dfs(TreeNode* here, int left, int right){  // check if the subtree rooted at here is a valid range within (left, right)
        if(!here) return true;
        if(left >= here->val || right <= here->val) return false;
        return dfs(here->left, left, here->val) && dfs(here->right, here->val, right);
    }
};

int main() {
    // test code (optional)
    return 0;
}