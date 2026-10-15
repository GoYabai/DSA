class Solution:
    def arrangeCoins(self, n: int) -> int:
        lo = 1
        hi = n
        while lo <= hi:
            curr = (lo + hi) // 2
            now = curr * (curr + 1) // 2
            if now < n:
                lo = curr + 1
            elif now > n:
                hi = curr - 1
            else:
                return curr
                
        return hi