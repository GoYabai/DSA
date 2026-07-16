#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> st;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp(st);
        int min = st.top();
        for (int i = 0; i < st.size(); i++)
        {
            if (temp.top() < min)
            {
                min = temp.top();
            }
            temp.pop();
        }
        return min;
    }
};
