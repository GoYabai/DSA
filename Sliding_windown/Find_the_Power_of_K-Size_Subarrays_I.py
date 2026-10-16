class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        ans = []
        for i in range(len(nums) - k + 1):
            temp = nums[i:k + i]
            condi = True
            for i in range(1, len(temp)):
                if not (temp[i] - temp[i - 1] == 1):
                    ans.append(-1)
                    condi = False
                    break
            if condi == True:
                ans.append(temp[-1])
        return ans
                
