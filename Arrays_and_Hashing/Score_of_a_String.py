class Solution:
    def scoreOfString(self, s: str) -> int:
        ans = 0
        for i in range(1, len(s)):
            curr = ord(s[i])
            prev = ord(s[i - 1])
            diff = abs(curr - prev)
            ans += diff
        return ans