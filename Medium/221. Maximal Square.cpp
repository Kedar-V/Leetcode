class Solution {
public:
    
    /*
      dp[r][c] will be 1/0 + min (of squares ending at adjacent squares)       
        
    */
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int H = matrix.size();
        int W = matrix[0].size();
        
        vector<vector<int>> dp (H, vector<int>(W));
        int ans = 0;
        for (int row = 0; row < H; ++row)
        {
            for(int colm = 0; colm < W; ++colm)
            {
                if(matrix[row][colm] == '1')
                {
                    dp[row][colm] = 1;
                    if (row > 0 && colm > 0)
                        dp[row][colm] += min({dp[row-1][colm-1], dp[row][colm-1], dp[row-1][colm]});

                    ans = max(dp[row][colm], ans);
                }
            }
        }
        return ans*ans;
    }
};
