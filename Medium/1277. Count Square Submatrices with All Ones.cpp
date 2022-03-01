class Solution {
public:
    int countSquares(vector<vector<int>>& mat) 
    {
        int row = mat.size();
        int colm = mat[0].size();
        
        vector<vector<int>> dp (row + 1, vector<int> (colm + 1, 0));
        
        int count = 0;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= colm; j++)
            {
                if (mat[i-1][j-1] == 1)
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + mat[i-1][j-1];
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};
