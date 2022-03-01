class Solution:
    
    def continue_top(self, visited, i, j, m, n):
        if i > 0:
            if not visited[i-1][j]:
                return True
        return False
    
    def continue_bottom(self, visited, i, j, m, n):
        if i < m-1:
            if not visited[i+1][j]:
                return True
        return False
    
    def continue_left(self, visited, i, j, m, n):
        if j > 0: 
            if not visited[i][j-1]:
                return True
        return False
    
    def continue_right(self, visited, i, j, m, n):
        if j < n-1:
            if not visited[i][j+1]:
                return True
        return False
    
    
    def generateMatrix(self, n: int) -> List[List[int]]:

        visited = [[False for j in range(n)] for i in range(n)]
        matrix = [[0 for j in range(n)] for i in range(n)]
        
        i = 0
        j = 0
        count = 1
        total = n*n + 1
        Flag = False
        while(not Flag):
            while(self.continue_right(visited, i, j, n, n)):
                # print('right')
                visited[i][j] = True
                # print(i, j)
                matrix[i][j] = count
                # print(matrix[i][j], end = " ")
                j += 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
                
            while(self.continue_bottom(visited, i, j, n, n)):
                # print('bottom')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                matrix[i][j] = count
                i += 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
            
            while(self.continue_left(visited, i, j, n, n)):
                # print('left')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                matrix[i][j] = count
                j -= 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
                    
            while(self.continue_top(visited, i, j, n, n)):
                # print('top')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                matrix[i][j] = count
                i -= 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
            
            if count == total-1:
                # print(matrix[i][j])
                Flag = True
                matrix[i][j] = count
        
        return matrix
        
