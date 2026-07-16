#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;



class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> mystack;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                int s = mystack.top(), tem = mystack.top();
                mystack.pop();
                s += mystack.top();
                mystack.push(tem);
                mystack.push(s);
            }
            else if (operations[i] == "C")
            {
                mystack.pop();
            }
            else if (operations[i] == "D")
            {
                int s = mystack.top() * 2;
                mystack.push(s);
            }
            else
            {
                mystack.push(stoi(operations[i]));
            }
        }
        int n = mystack.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += mystack.top();
            mystack.pop();
        }
        return ans;

    }
};