#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        if (s[0] != '0')
        {
            dp[1] = 1;
        }
        else
        {
            dp[1] = 0;
        }
        for (int i = 2; i < s.size() + 1; i++)
        {
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i] + dp[i - 1];
            }
            if (s[i - 2] == '1')
            {
                dp[i] = dp[i] + dp[i - 2];
            }
            else if (s[i - 2] == '2' && s[i - 1] <= '6')
            {
                dp[i] = dp[i] + dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};
