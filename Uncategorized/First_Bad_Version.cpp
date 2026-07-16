#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int n) //delete this fuction to work
{
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            bool result = isBadVersion(mid);
            if (result == true)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};