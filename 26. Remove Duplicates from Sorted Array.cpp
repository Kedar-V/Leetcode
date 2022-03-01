class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {   
        
        if (nums.size() == 1 || nums.size() == 0)
            return nums.size();
        for (int i = 0; i < nums.size()-1; i++)
        {
            int j = i+1;
            while (nums[j] == nums[i] && j < nums.size())
            {
                nums.erase(nums.begin() + j);
            }
        }
        return nums.size();
    }
};
