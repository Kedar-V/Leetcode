const int maximum = 1000;
class Solution {    
public:

    int len1;
    int len2;
    
    int longestCommonSubsequence(string text1, string text2)
    {
        len1 = int(text1.length());
        len2 = int(text2.length());
        int dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            { 
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
