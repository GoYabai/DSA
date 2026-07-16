#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                st.push(s[i]);
            }
            if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                if (st.empty())
                {
                    return false;
                }
                if (s[i] == ']')
                {
                    if (st.top() != '[')
                    {
                        return false;
                    }
                    st.pop();
                }
                else if (s[i] == '}')
                {
                    if (st.top() != '{')
                    {
                        return false;
                    }
                    st.pop();
                }
                else
                {
                    if (st.top() != '(')
                    {
                        return false;
                    }
                    st.pop();
                }
            }
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};
