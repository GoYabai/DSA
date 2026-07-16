#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int num : bills)
        {
            if (num == 5)
            {
                five++;
            }
            else if (num == 10)
            {
                five--;
                ten++;
                if (five < 0)
                {
                    return false;
                }
            }
            else
            {
                if (ten > 0)
                {
                    ten--;
                    five--;
                    if (ten < 0 || five < 0)
                    {
                        return false;
                    }
                }
                else
                {
                    five -= 3;
                    if (five < 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};