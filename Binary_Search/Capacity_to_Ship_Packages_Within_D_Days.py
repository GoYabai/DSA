class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l = max(weights)
        r = sum(weights)
        ans = 10000000
        while l <= r:
            mid = (l + r) // 2
            d = 1
            temp = 0
            for i in range(len(weights)):
                if temp + weights[i] <= mid:
                    temp += weights[i]
                else:
                    temp = weights[i]
                    d += 1
            
            if d <= days:
                ans = min(mid, ans)
                r = mid - 1
            elif d > days:
                l = mid + 1
        
        return ans

                