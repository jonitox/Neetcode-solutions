#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj; // adjacency list

        // build the graph
        for(int i=0; i<wordList.size(); ++i){
            for(int j=i+1; j<wordList.size(); ++j){
                if(isAdjacent(wordList[i], wordList[j])){ // if they differ by one letter
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
            if(isAdjacent(wordList[i], beginWord))
                adj[beginWord].push_back(wordList[i]);
        }

        // BFS
        queue<string> q;
        map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord]= true;
        int dis =0;  
        while(!q.empty()){
            dis++;
            int size = q.size();
            while(size--){ // process all nodes at the current distance
                string& here = q.front();
                q.pop();
                if(here == endWord) return dis;
                for(string& there: adj[here])
                    if(!vis[there]) {
                        q.push(there);
                        vis[there]=true;
                    }
                }
        }
        return 0;
    }

    // check if two words differ by exactly one letter
    bool isAdjacent(string& a, string& b){
        int cnt = 0;
        for(int i=0; i < a.length(); ++i){
            if(a[i] != b[i]) cnt++;
        }
        return cnt==1;
    }
};

int main() {
    // test code (optional)
    return 0;
}