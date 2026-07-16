#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curr = 0;
        for (int num : nums)
        {
            if (curr < 0)
            {
                curr = 0;
            }
            curr += num;
            maxSum = max(maxSum, curr);
        }
        return maxSum;
    }
};
