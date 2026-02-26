#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Visited array to keep track of cloned nodes, index by node value (assuming node values are 1-indexed and <= 100)
    vector<Node*> vis =  vector<Node*>(101, nullptr);
    Node* cloneGraph(Node* node) {   
        if (!node) return nullptr;  
        return dfs(node);
    }

    // DFS approach
    Node* dfs(Node* node){
        if (vis[node->val]) return vis[node->val];
        Node* n = new Node(node->val);
        vis[node->val] = n;
        for(auto& neigh: node->neighbors) {
            (n->neighbors).push_back(vis[neigh->val] == nullptr ? dfs(neigh) : vis[neigh->val]);
        }
        return n;
    }


};


int main() {
    // test code (optional)
    return 0;
}