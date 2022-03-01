class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        int freq = 0;
        int val = 1;
        int n = nums.size();
        
        vector<int> ans;
        while (val < n)
        {
            for (int i = 0; i < nums[freq]; i++)
                ans.push_back(nums[val]);
            val += 2;
            freq += 2;
        }
        return ans;
    }
};
