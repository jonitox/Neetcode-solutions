#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st, minst; // minst: stack to keep track of minimums
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty())
            minst.push(val);
        else 
            minst.push(min(val, minst.top())); // push the minimum so far
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();   
    }
    
    int getMin() {
        return minst.top();
    }
};



int main() {
    // test code (optional)
    return 0;
}