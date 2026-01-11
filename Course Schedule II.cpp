#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        // build graph
        for(auto& v: prerequisites){
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }

        // topological sort using Kahn's algorithm
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(indeg[i] == 0)
                q.push(i);
        }

        vector<int> ret;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ret.push_back(node);

            for(int t: adj[node]){
                indeg[t]--;
                if(indeg[t]==0)
                    q.push(t);
            }
        }   

        if(ret.size() == numCourses) // valid topological order exists
            return ret;
        else
            return {};

    }
};



int main() {
    // test code (optional)
    return 0;
}