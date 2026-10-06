

class Solution:
    def replaceElements(self, arr: list[int]) -> list[int]:
        for i in range(len(arr)):
            if i == len(arr) - 1:
                arr[i] = -1
                break
            great = arr[i + 1]
            for j in range(i + 1, len(arr)):
                great = max(great, arr[j])
            arr[i] = great
        return arr