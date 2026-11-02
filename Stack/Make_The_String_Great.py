class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if len(stack) == 0:
                stack.append(s[i])
                continue
            top = stack[-1]
            if abs(ord(top) - ord(s[i])) == 32:
                stack.pop()
            else:
                stack.append(s[i])
        return "".join(stack)
            
