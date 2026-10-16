class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = 99999999
        for i in range(len(blocks) - k + 1):
            temp = blocks[i:k + i]
            num_W = 0
            for color in temp:
                if color == "W":
                    num_W += 1
            if num_W < ans:
                ans = num_W
        return ans