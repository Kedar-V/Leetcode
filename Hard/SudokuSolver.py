class Solution:

    def isValid(self, board, x, y, num):

        # Check Row:
        for i in range(9):
            if board[i][y] is not ".":
                # print(board[i][y], (i, y))
                if int(board[i][y]) == num:
                    return False
        
        # Check Column
        for j in range(9):
            if board[x][j] is not ".":
                if int(board[x][j]) == num:
                    return False

        # Check 3x3 box
        for i in range(x - x%3, x + 3 - x%3):
            for j in range(y - y%3, y + 3 - y%3):
                if board[i][j] is not ".":
                    if int(board[i][j]) == num:
                        return False
        
        return True
        
    def findEmptySpot(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    return (i, j)
        return -1

    def print_board(self, board):
        for i in range(9):
            print(board[i])
            

    def solverHelper(self, board):
        temp = self.findEmptySpot(board)
        if temp == -1:
            return True

        x = temp[0]
        y = temp[1]

        # Try all numbers
        for num in range(1, 10):
            if self.isValid(board, x, y, num):
                board[x][y] = str(num)
                
                if self.solverHelper(board):
                    return True
                  
                # Backtracking
                board[x][y] = "."
        
        return False

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        self.solverHelper(board)

        

        
