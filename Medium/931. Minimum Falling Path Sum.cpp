const int maximum = 100;
class Solution {
public:

        int minFallingPathSum_helper(vector<vector<int>>& A, int row, int colm, int len, int pathlen, int dp[][maximum])
    {

        if (pathlen == len)
        {
            if (colm < 0 || colm >= len)
                return 0;
            if (row < 0 || row >= len)
                return 0;
        }
        else
        {
            if (colm < 0 || colm >= len)
                return INT_MAX - 101;
            if (row < 0 || row >= len)
                return INT_MAX - 101;
        }

        if (dp[row][colm] != 0)
            return dp[row][colm];

        int min = INT_MAX;

        for (int j = -1; j <= 1; j++)
        {
            int temp = minFallingPathSum_helper(A, row+1, colm+j, len, pathlen+1, dp);
            if (temp < min)
                min = temp;
        }
        return dp[row][colm] = A[row][colm] + min ;

    }

    int minFallingPathSum(vector<vector<int>>& A)
    {
        int min = INT_MAX;

        int rows = int(A.size());
        int dp[rows][maximum];

        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < rows; i++)
        {
            int temp = minFallingPathSum_helper(A, 0, i, rows, 0, dp);
            if (temp < min)
                min = temp;
        }
        return min;
    }
};
