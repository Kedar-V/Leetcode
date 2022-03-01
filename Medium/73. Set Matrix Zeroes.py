class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        rows = {}
        colms = {}
        # for row in matrix:
        #     print(row)
            
        m = len(matrix)
        n = len(matrix[0])
        
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0: 
                    rows[row] = True
                    colms[col] = True
                    
        for row in range(m):
            for col in range(n):
                
                if row in rows or col in colms:
                    matrix[row][col] = 0
                    
        
        # print("AFTER")
        # for row in matrix:
        #     print(row)
                    
                        
                        
                        
