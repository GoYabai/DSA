#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                temp++;
            }
            else
            {
                temp = 0;
            }
            if (temp > max)
                {
                    max = temp;
                }
        }
        return max;
    }

int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    int max = findMaxConsecutiveOnes(nums);
    cout << max << "\n";
}