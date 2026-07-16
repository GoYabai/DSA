#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a,
        const vector<int>& b)
        {
            return a[1] < b[1];
        });
        int n = intervals.size();
        int ans = 1;
        int end_time = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= end_time)
            {
                ans++;
                end_time = intervals[i][1];
            }
        }
        return n - ans;
    }
};