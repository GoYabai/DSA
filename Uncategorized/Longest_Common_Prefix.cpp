#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
        {
            return "";
        }
        int shortest = strs[0].size();
        int shortest_id = 0;
        int n = strs.size();
        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].size() < shortest)
            {
                shortest = strs[i].size();
                shortest_id = i;
            }
        }
        for (int i = 0; i < shortest; i++)
        {
            char curr = strs[shortest_id][i];
            for (int j = 0; j < n; j++)
            {
                if (j == shortest_id)
                {
                    continue;
                }
                if (strs[j][i] != curr)
                {
                    return strs[shortest_id].substr(0, i);
                }
            }
        }
        return strs[shortest_id];
    }
};