#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> c_s;
        unordered_map<char, int> c_t;
        for (int i = 0; i < s.size(); i++)
        {
            c_s[s[i]] += 1;
            c_t[t[i]] += 1;
        }
        return c_s == c_t;
    }
};
