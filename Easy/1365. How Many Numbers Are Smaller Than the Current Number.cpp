class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int len = nums.size();
        vector <int> ans(len, 0);
        
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                    continue;
                if (nums[j] < nums[i])
                    ans[i]++;
            }
        }
                
        
        return ans;
    }
};
