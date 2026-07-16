#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        int i = 0, j = 0;
        string ans = "";
        while (i < s1 && j < s2)
        {
            ans += word1[i];
            i++;
            ans += word2[j];
            j++;
        }
        while (i < s1)
        {
            ans += word1[i];
            i++;
        }
        while (j < s2)
        {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};