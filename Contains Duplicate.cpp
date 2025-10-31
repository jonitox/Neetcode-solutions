#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s; // to store seen numbers
        for(int& a: nums)
            if(s.count(a))
                return true;
            else
                s.insert(a);
        return false;
    }
};

int main() {
    // test code (optional)
    return 0;
}