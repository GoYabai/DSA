#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p = 1;
        int zero = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                p *= nums[i];
            }
            else if (nums[i] == 0)
            {
                zero++;
            }
        }
        if (zero > 1)
        {
            return vector<int>(nums.size(), 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (zero > 0)
            {
                if (nums[i] != 0)
                {
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(p);
                }
            }
            else
            {
                if (nums[i] != 0)
                {
                    ans.push_back(p / nums[i]);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};
