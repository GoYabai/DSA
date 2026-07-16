#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string input;
    string temp = "";
    stack<char> rv;
    char key;
    cin >> input;
    cin >> key;
    int id = 0;
    bool stt = false;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == key)
        {
            stt = true;
            id = i;
            rv.push(input[i]);
            break;
        }
        rv.push(input[i]);
    }
    if (stt)
    {
        while (!rv.empty())
        {
            char t = rv.top();
            rv.pop();
            temp += t;
        }
        for (int i = id + 1; i < input.size(); i++)
        {
            temp += input[i];
        }
        cout << temp;
    }
    else
    {
        cout << input;
    }
    return 0;
}