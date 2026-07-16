class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        while (low <= high)
        {
            long long mid = low - (low - high) / 2;
            if (mid*mid > x)
            {
                high = mid - 1;
            }
            else if (mid*mid < x)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return high;
    }
};