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
    int ans =0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
    
    // DFS approach, pathMax is the maximum value on the path from root to current node
    void dfs(TreeNode* here, int pathMax){
        if(here==nullptr) return;
        if(pathMax <= here->val) ans++; // current node is good
        if(here->left){
            dfs(here->left, max(pathMax, here->val));
        }
        if(here->right){
            dfs(here->right, max(pathMax, here->val));
        }
        return;
    }
};


int main() {
    // test code (optional)
    return 0;
}