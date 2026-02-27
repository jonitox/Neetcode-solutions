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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(!root) return {};
        vector<vector<int>> ret;
        // BFS approach
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            // iterate through the current level, queue size is the number of nodes in the current level
            for(int i=0; i<sz; ++i){
                TreeNode* here = q.front();
                q.pop();
                level.push_back(here->val);
                if(here->left) q.push(here->left);
                if(here->right) q.push(here->right);
            }
            ret.push_back(level); // add the current level to the result
        }        
        return ret;
    }

    
};

int main() {
    // test code (optional)
    return 0;
}