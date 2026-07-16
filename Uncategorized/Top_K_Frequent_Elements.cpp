#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (int num : nums)
        {
            hm[num]++;
        }
        vector<pair<int, int>> arr;
        for (auto& p : hm)
        {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i].second);
        }
        return res;
    }
};
