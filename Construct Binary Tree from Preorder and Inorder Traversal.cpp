#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int> pos; // store the index of each value in the inorder traversal for O(1) access
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); ++i){
            pos[inorder[i]]=i;
        }
        return build(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }

    // recursive function to build the tree
    // preL, preR: the current range in the preorder traversal
    // inL, inR: the current range in the inorder traversal
    TreeNode* build(int preL, int preR, int inL, int inR, vector<int>& preorder, vector<int>& inorder){
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);
        if(preL==preR) return root;
        int idxIn=pos[rootVal]; // index of the root in the inorder traversal
        int leftSubSize = idxIn-inL; // size of the left subtree
        int rightSubSize = inR-idxIn; // size of the right subtree
        if(leftSubSize)
            root->left=build(preL+1, preL+leftSubSize, inL, idxIn-1, preorder, inorder);
        if(rightSubSize)
            root->right=build(preL+leftSubSize+1, preR, idxIn+1, inR, preorder, inorder);
        return root;
    }
};

int main() {
    // test code (optional)
    return 0;
}