#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*  using min-heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int a: nums){
                m[a]++; // count frequency of each element
        }   
        priority_queue<pair<int,int>> pq; // min-heap to keep top k frequent elements
        for(auto &[a, cnt]: m){
            pq.push({-cnt, a});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
*/

    //  using bucket sort
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int a: nums){
                m[a]++; // count frequency of each element
        } 
    
        vector<vector<int>> freq(nums.size()+1); // freq[i]: list of elements that appear i times
        for(auto& [a, cnt]: m){
            freq[cnt].push_back(a);
        }

        vector<int> ans;
        for(int i= freq.size()-1; i>0; --i){ // iterate from highest frequency to lowest
            for(int a: freq[i]){
                ans.push_back(a);
                if(ans.size()==k)
                    return ans;
            }
        }
    }
};


int main() {
    // test code (optional)
    return 0;
}