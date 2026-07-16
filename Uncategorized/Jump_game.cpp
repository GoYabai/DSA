#include <vector>
using namespace std;

// Dumb-ass
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return rc(nums, 0);
    }

    bool rc(vector<int>& nums, int s)
    {
        if (s == nums.size() - 1)
        {
            return true;
        }
        int step = nums[s];
        if (step == 0)
        {
            return false;
        }
        for (int i = 1; i <= step; i++)
        {
            if (rc(nums, s + i))
            {
                return true;
            }
        }
        return false;
    }
};

// Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_reachable) {
                return false;
            }
            max_reachable = max(max_reachable, i + nums[i]);
            if (max_reachable >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};