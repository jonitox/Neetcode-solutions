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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }

    // dfs to compute height and check balance
    int dfs(TreeNode* here, bool& balanced){
        if(!here) return 0;
        int lh = dfs(here->left, balanced);
        int rh = dfs(here->right, balanced);
        if(abs(lh-rh) > 1) balanced = false; // not balanced for this node
        return max(lh, rh)+1;
    }
};


int main() {
    // test code (optional)
    return 0;
}