#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star; // stack for "*", saves indices
        stack<int> leftp; // stack for "(", saves indices
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='*')
                star.push(i);
            else if(s[i]=='(')
                leftp.push(i);
            else {
                if(!leftp.empty()) // check '(' stack first
                    leftp.pop(); 
                else if(!star.empty()) // if '(' stack is empty, use '*' as '('
                    star.pop();
                else
                    return false;
            }
        }
        while(!leftp.empty()){
             // for remaning '(', '*' with bigger indices should be used as ')'
            if(!star.empty() && star.top() > leftp.top()) {
                star.pop();
                leftp.pop();
            }
            else
                return false;
        }
        return true;
    }
};


int main() {
    // test code (optional)
    return 0;
}