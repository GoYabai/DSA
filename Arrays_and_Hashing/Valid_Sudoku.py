class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Row
        for r in range(9):
            seen = set()
            for i in range(9):
                if board[r][i] == ".":
                    continue
                elif board[r][i] in seen:
                    return False
                else:
                    seen.add(board[r][i])
        
        # Column
        for c in range(9):
            seen = set()
            for i in range(9):
                if board[i][c] == ".":
                    continue
                elif board[i][c] in seen:
                    return False
                else:
                    seen.add(board[i][c])
        
        # Sub-boxes
        for b in range(9):
            seen = set()
            for i in range(3):
                for j in range(3):
                    row = (b // 3) * 3 + i
                    col = (b % 3) * 3 + j

                    if board[row][col] == ".":
                        continue
                    elif board[row][col] in seen:
                        return False
                    else:
                        seen.add(board[row][col])

        return True
