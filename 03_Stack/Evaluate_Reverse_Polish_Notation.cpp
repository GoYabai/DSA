#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i ++)
        {
            if (tokens[i] == "+")
            {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            }
            else if (tokens[i] == "-")
            {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            }
            else if (tokens[i] == "*")
            {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            }
            else if (tokens[i] == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            }
            else
            {
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};
