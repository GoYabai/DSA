#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        int L = 0;
        unordered_set<char> map;
        for (int R = 0; R < s.size(); R++)
        {
            while (map.find(s[R]) != map.end())
            {
                map.erase(s[L]);
                L++;
            }
            if (map.find(s[R]) == map.end())
            {
                map.insert(s[R]);
            }
            m = max(m, R - L + 1);
        }
        return m;
    }
};


