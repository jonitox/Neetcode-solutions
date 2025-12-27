#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char&c: s){
            if(c == '(' || c == '{' || c == '[') // opening bracket
                st.push(c);
            else if(c==')' && !st.empty() && st.top() == '(') // closing bracket matches top of stack
                st.pop();
            else if(c=='}' && !st.empty() && st.top() == '{')
                st.pop();
            else if(c==']' && !st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
        return st.empty(); // all opening brackets should be matched
    }
};

int main() {
    // test code (optional)
    return 0;
}