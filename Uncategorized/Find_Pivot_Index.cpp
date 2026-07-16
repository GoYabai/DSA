#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pi = 0;
        while (pi < nums.size())
        {
            int pre_left = 0;
            int pre_right = 0;
            for (int i = 0; i < pi; i ++)
            {
                pre_left += nums[i];
            }
            for (int i = pi + 1; i < nums.size(); i++)
            {
                pre_right += nums[i];
            }
            if (pre_left == pre_right)
            {
                return pi;
            }
            pi++;
        }
        return -1;
    }
};