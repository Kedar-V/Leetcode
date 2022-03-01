class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1)
            return 0;
        
        vector<int> dp(n, 100000);
        dp[n-1] = 0;
        
        for (int i = n-2; i >= 0; i--){
    
            for (int j = nums[i]; j > 0; j--){
                
                if (i + j >= n-1){
                    dp[i] = 1;
                    break;
                }
                
                dp[i] = min(dp[i], 1+dp[i+j]);
            
            }
            
        }
        // for (int i: dp)
        //     cout << i << " ";
        // cout << endl;
        
        return dp[0];
    }
};
