#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string in;
    getline(cin, in);
    stack<char> r_in;
    for (int i = 0; i < in.size(); i++)
    {
        r_in.push(in[i]);
    }
    int n = r_in.size();
    for (int i = 0; i < n; i++)
    {
        cout << r_in.top();
        r_in.pop();
    }
    cout << "\n";
    return 0;
}