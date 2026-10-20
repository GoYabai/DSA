class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        m = 0
        for c in s:
            m = max(m, len(stack))
            if c == "(":
                stack.append(c)
            elif c == ")":
                stack.pop()
        return m
            
