#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> st1;
    
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int s = st.size();
        for (int i = 0; i < s; i++) {
            st1.push(st.top());
            st.pop();
        }
        
        int val = st1.top();   
        st1.pop();
        
        while(!st1.empty()) {
            st.push(st1.top());
            st1.pop();
        }
        return val;
    }
    
    int peek() {
        int s = st.size();
        for (int i = 0; i < s; i++) {
            st1.push(st.top()); 
            st.pop();
        }
        
        int val = st1.top();   
        
        while(!st1.empty()) {
            st.push(st1.top());
            st1.pop();
        }
        return val;
    }
    
    bool empty() {
        return st.empty();
    }
};