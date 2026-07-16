#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());
        int ans = R;

        while (L <= R) {
            int mid = L + (R - L) / 2; 
            long long temp = 0;
            
            for (int pile : piles) {
                temp += (pile + mid - 1) / mid; 
            }
            
            if (temp <= h) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    }
};