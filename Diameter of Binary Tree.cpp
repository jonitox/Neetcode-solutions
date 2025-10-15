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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0; 
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* here, int& ans){ // dfs returns height of the tree rooted at here
        if(here == nullptr) return 0;
        int leftH = dfs(here->left, ans);
        int rightH = dfs(here->right, ans);
        ans = max(ans, leftH+rightH);
        return max(leftH,rightH)+1;
    }
};



int main() {
    // test code (optional)
    return 0;
}