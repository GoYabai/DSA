#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
    }
private:
    int partition(vector<int>& nums, int f, int l)
    {
        int pivot = nums[l];
        int i = f - 1;
        int j = f;
        while (j < l)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        i++;
        swap(nums[i], nums[l]);
        return i;
    }
    void quicksort(vector<int>& nums, int f, int l)
    {
        if (f < l)
        {
            int mid = partition(nums, f, l);
            quicksort(nums, f, mid - 1);
            quicksort(nums, mid + 1, l);
        }
    }
};