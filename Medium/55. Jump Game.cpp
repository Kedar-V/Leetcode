class Solution {
public:
    
    bool canJump(vector<int>& nums) {
       
        int n = nums.size();
        
        if (n == 1)
            return true;
        
        bool dp[n];
        memset(dp, 0, n);
        
        for (int i = n-1; i >= 0; i--){
    
            for (int j = nums[i]; j > 0; j--){
                if (i+j >= n-1 || dp[i+j]){
                    dp[i] = true;
                    break;
                }
            
            }
            
        }
        // for (int i: dp)
        //     cout << i << " ";
        // cout << endl;
        
        return dp[0];
    }
};
