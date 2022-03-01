#define for(i,a,b) for(int i=(a);i<(b);i++) 

class Solution {
public:
    
    void print_dp(vector<vector<int>>& dp, int m, int n){
        
        for (i, 0, m){
            for (j, 0, n){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // for (i, 0, m) {dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : 1 ;}
        // for (i, 0, n) {dp[0][i] = (obstacleGrid[0][i] == 1) ? 0 : 1 ;}
        
        for (i, 1, m+1){
            
            for (j, 1, n+1){
                
                if (i == 1 && j == 1 && obstacleGrid[i-1][j-1] == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                }
                
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                
            }
            
        }
        // print_dp(obstacleGrid, m, n);
        // cout << "---------\n";
        // print_dp(dp, m+1, n+1);
        return dp[m][n];
        
        
        
    }
};
