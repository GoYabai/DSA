#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int l = nums.size();
        for (int num : nums)
        {
            s += num;
        }
        if (s % 2 != 0)
        {
            return false;
        }
        s /= 2;
        vector<vector<int>> dp(l + 1, vector<int>(s + 1, 0));
        for (int i = 1; i < l + 1; i++)
        {
            for (int j = 1; j < s + 1; j++)
            {
                if (nums[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                }
            }
        }
        return dp[l][s] == s;
    }
};
