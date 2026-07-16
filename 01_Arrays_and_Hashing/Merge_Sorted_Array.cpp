#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> cp(nums1.begin(), nums1.begin() + m);
        int id = 0, i = 0, j = 0;
        while (id < m + n)
        {
            if (j == n || (i < m && cp[i] <= nums2[j]))
            {
                nums1[id] = cp[i];
                id++;
                i++;
            }
            else
            {
                nums1[id] = nums2[j];
                id++;
                j++;
            }
        }
    }
};