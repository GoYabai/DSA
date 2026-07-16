#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int ans = 0;
        while (sell < prices.size())
        {
            if (prices[sell] > prices[buy])
            {
                ans = max(ans, prices[sell] - prices[buy]); 
            }
            else
            {
                buy = sell;
            }
            sell++;
        }
        return ans;
    }
};
