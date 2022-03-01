class Solution {
public:
    
    bool binarySearch(vector<int>& nums, int n, int len, int start)
    {
        int i = start;
        int j = len-1;
        while (i <= j)
        {
            int mid = i + (j-i)/2;
            if (nums[mid] == n)
            {
                cout << n << endl;
                return true;
            }
            
            else if(n < nums[mid])
                j = mid - 1;
                
            else
                i = mid + 1;
        }
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) 
    {
//         sort(nums.begin(), nums.end());
        int len = nums.size();
        
//         for (int i = 0; i < len; i++)
//         {
//             if (binarySearch(nums, nums[i], len, i+1))
//                 return true;
//         }
//         return false;
        
        unordered_map<int, bool> hash;
        
        for (int i = 0; i < len; i++)
        {
            if (hash.find(nums[i]) == hash.end())
                hash[nums[i]] = true;
            else
                return true;
        }
        return false;
        
    }
};
