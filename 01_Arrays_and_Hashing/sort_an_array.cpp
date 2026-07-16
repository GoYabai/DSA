#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> L(nums.begin() + low, nums.begin() + mid + 1);
        vector<int> R(nums.begin() + mid + 1, nums.begin() + high + 1);
        int i = 0;
        int j = 0;
        int curr = low;
        while (i < L.size() && j < R.size())
        {
            if (L[i] < R[j])
            {
                nums[curr] = L[i];
                curr++;
                i++;
            }
            else
            {
                nums[curr] = R[j];
                curr++;
                j++;
            }
        }
        while (i < L.size())
        {
            nums[curr] = L[i];
            curr++;
            i++;
        }
        while (j < R.size())
        {
            nums[curr] = R[j];
            curr++;
            j++;
        }
    }
    void mergesort(vector<int>& nums, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            mergesort(nums, low, mid);
            mergesort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }
};