#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int h = heights.size(), w = heights[0].size();
        unordered_set<int> atl; // cells reachable by Atlantic ocean
        unordered_set<int> pac; // cells reachable by Pacific ocean
        queue<int> atlQ, pacQ;  // queues for BFS
    
        for(int i=0; i<w; ++i){
            pac.insert(i); 
            pacQ.push(i);
            atl.insert(w*(h-1)+i);
            atlQ.push(w*(h-1)+i);
        }
        for(int i=0; i<h; ++i){
            pac.insert(w*i);
            pacQ.push(w*i);
            atl.insert(w*i + w-1);
            atlQ.push(w*i + w-1);
        }

        bfs(atlQ, atl, heights);
        bfs(pacQ, pac, heights);

       
        
        vector<vector<int>> ans;
        for(int c: atl){
            if(pac.find(c) != pac.end()) // if cell is reachable by both oceans
                ans.push_back({c/w, c%w});
        }
        return ans;
    }

    void bfs(queue<int>& q, unordered_set<int>& ocean, vector<vector<int>>& heights){
        int h = heights.size(), w = heights[0].size();
        while(!q.empty()){
            int x = q.front()/w, y = q.front()%w;
            q.pop();

            for(int i=0; i<4; ++i){
                int adjX = x + dx[i], adjY = y + dy[i];
                if(adjX < 0 || adjX >= h || adjY < 0 || adjY >= w) continue; // out of bounds
                if(heights[adjX][adjY] >= heights[x][y] && ocean.find(adjX*w + adjY) == ocean.end()){ // if adjacent cell is higher or equal and not visited
                    ocean.insert(adjX*w + adjY);
                    q.push(adjX*w + adjY);
                }
            }
        }
    }
};


int main() {
    // test code (optional)
    return 0;
}