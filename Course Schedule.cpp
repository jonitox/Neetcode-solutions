#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Kahn's algorithm for topological sorting for cycle detection
     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(vector<int>& p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q; 
        for(int i=0; i<numCourses; ++i)
            if(indegree[i]==0)
                q.push(i);
        int cnt =0;
        while(!q.empty()){
            int here = q.front();
            q.pop();
            cnt++;
            for(int there: adj[here]){
                indegree[there]--;
                if(indegree[there]==0)
                    q.push(there);
            }
        }
        return cnt==numCourses;
     }


/* DFS for cycle detection
    vector<vector<int>> adj;
    vector<bool> vis, fin;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
        vis.assign(numCourses, false);
        fin.assign(numCourses, false);
        
        for(vector<int>& p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        bool cycle = false;
        for(int i=0; i<numCourses; ++i){
            if(!vis[i]){
                dfs(i, cycle);
                if(cycle) return false;
            }
        }
        return true;
    }

    void dfs(int here, bool& cycle){
        vis[here]=true;

        for(int& there: adj[here]){
            if(!vis[there]) 
                dfs(there, cycle);
            if(vis[there] && !fin[there]) // back edge found, cycle detected
                cycle= true;
        }
        fin[here]=true;
    }
*/
};


int main() {
    // test code (optional)
    return 0;
}