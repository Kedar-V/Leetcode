class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        # print(m, n)
        # print(dp)
        
        for i in range(m):
            for j in range(n):
                
                if i == 0 and j == 0:
                    dp[0][0] = grid[0][0]
                    continue
                
                elif i == 0:
                    # print(i, j)
                    dp[0][j]
                    grid[0][j]
                    dp[0][j] = dp[0][j-1] + grid[0][j]
                
                elif j == 0:
                    dp[i][0] = dp[i-1][0] + grid[i][0]
                    
                else:
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
        
        # for i in dp:
        #     print(i)
        return dp[m-1][n-1]
