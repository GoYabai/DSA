#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hm;
        int ans = 0, cnt = 0;
        for (int num : nums)
        {
            hm[num] += 1;
            if (hm[num] > cnt)
            {
                ans = num;
                cnt = hm[num];
            }
        }
        return ans;
    }
};