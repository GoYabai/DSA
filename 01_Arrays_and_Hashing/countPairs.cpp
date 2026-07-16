#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int target;
    cin >> n >> target;
    int re = 0;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] < target)
            {
                re++;
            }
        }
    }
    cout << re;
    return 0;
}