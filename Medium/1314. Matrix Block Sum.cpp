class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int row = mat.size();
        int colm = mat[0].size();
        vector<vector<int>> ans(row, vector<int> (colm));
        
        vector<vector<int>> dp(row+1, vector<int> (colm+1, 0));
        
        
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= colm; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colm; j++)
            {
                int r1 = max (0, i - k) + 1;
                int c1 = max (0, j - k) + 1;
                int r2 = min (i + k + 1, row);
                int c2 = min (j + k + 1, colm);
                
                ans[i][j] = dp[r2][c2] + dp[r1-1][c1-1] - dp[r1-1][c2] - dp[r2][c1-1];  
            }
        }
        return ans;
    }
};
