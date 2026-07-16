#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    unordered_map<char, string> map;
    int cnt = 0;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (map.find(input[i]) == map.end())
        {
            string temp = "" + input[i];
            for (int j = i + 1; j < input.size(); j++)
            {
                if (input[j] != input[i])
                {
                    temp += input[j];
                }
            }
            map[input[i]] = temp;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}