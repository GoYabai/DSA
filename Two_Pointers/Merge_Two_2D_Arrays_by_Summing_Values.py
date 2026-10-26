class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        ans = []
        l = 0
        r = 0
        while l < len(nums1) and r < len(nums2):
            id1, num1 = nums1[l][0], nums1[l][1]
            id2, num2 = nums2[r][0], nums2[r][1]
            if id1 < id2:
                ans.append([id1, num1])
                l += 1
            elif id1 > id2:
                ans.append([id2, num2])
                r += 1
            else:
                ans.append([id1, num1 + num2])
                l += 1
                r += 1

        while l < len(nums1):
            ans.append([nums1[l][0], nums1[l][1]])
            l += 1

        while r < len(nums2):
            ans.append([nums2[r][0], nums2[r][1]])
            r += 1
        
        return ans
        