import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        ans = 100000000000
        while l <= r:
            mid = (l + r) // 2
            time = 0
            for pile in piles:
                time += math.ceil(pile / mid)
            if time <= h:
                ans = min(ans, mid)
                r = mid - 1
            elif time > h:
                l = mid + 1
        return ans
