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
    
    
    def spiralOrder(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        visited = [[False for j in range(n)] for i in range(m)]
        
        i = 0
        j = 0
        count = 0
        total = m*n
        Flag = False
        spiral = []
        while(not Flag):
            while(self.continue_right(visited, i, j, m, n)):
                # print('right')
                visited[i][j] = True
                # print(i, j)
                spiral.append(matrix[i][j])
                # print(matrix[i][j], end = " ")
                j += 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
                
            while(self.continue_bottom(visited, i, j, m, n)):
                # print('bottom')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                spiral.append(matrix[i][j])
                i += 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
            
            while(self.continue_left(visited, i, j, m, n)):
                # print('left')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                spiral.append(matrix[i][j])
                j -= 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
                    
            while(self.continue_top(visited, i, j, m, n)):
                # print('top')
                visited[i][j] = True
                # print(i, j)
                # print(matrix[i][j], end = " ")
                spiral.append(matrix[i][j])
                i -= 1
                count += 1
                if count == total-1:
                    Flag = True
                    break
            
            if count == total-1:
                # print(matrix[i][j])
                Flag = True
                spiral.append(matrix[i][j])
        
        return spiral
