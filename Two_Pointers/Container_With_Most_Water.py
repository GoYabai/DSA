class Solution:
    def maxArea(self, heights: List[int]) -> int:
        ans = 0
        l, r = 0, len(heights) - 1
        while l < r:
            h = min(heights[l], heights[r])
            w = r - l
            temp = h * w
            ans = max(temp, ans)
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
        return ans
