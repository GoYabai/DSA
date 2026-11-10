class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        l_r, r_r = 0, len(matrix) - 1
        while l_r <= r_r:
            m_r = (l_r + r_r) // 2
            if matrix[m_r][0] < target:
                l_r = m_r + 1
            elif matrix[m_r][0] > target:
                r_r = m_r - 1
            elif matrix[m_r][0] == target:
                return True

        if r_r < 0:
            return False

        row = r_r 

        l_c, r_c = 0, len(matrix[0]) - 1
        while l_c <= r_c:
            m_c = (l_c + r_c) // 2
            if matrix[row][m_c] < target:
                l_c = m_c + 1
            elif matrix[row][m_c] > target:
                r_c = m_c - 1
            elif matrix[row][m_c] == target:
                return True
                
        return False