class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        *_, last_word = s.split(" ")
        l = len(last_word)
        return l