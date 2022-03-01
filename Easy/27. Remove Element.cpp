class Solution {
public:
    
    int first(vector<int>& arr, int low, int high, int find)
    {
        if (low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        
        if (arr[mid] == find && (arr[mid-1] < find || mid == 0))
            return mid;
        
        if (arr[mid] > find)
            first(arr, low, mid - 1, find);
        
        return first(arr, mid+1, high, find);
    }
    
    int last(vector<int>& arr, int low, int high, int find)
    {
        if (low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        
        if (arr[mid] == find && (arr[mid+1] > find || mid == arr.size() - 1))
            return mid;
        
        if (arr[mid] > find)
            last(arr, low, mid - 1, find);
        
        return last(arr, mid+1, high, find);
    }
    
    int removeElement(vector<int>& nums, int val) 
    {
        
        vector<int> temp;
        
        for (int i : nums)
        {
            if (i != val)
                temp.push_back(i);
        }
        int new_len = temp.size();
        for (int i = 0; i < new_len; i++)
            nums[i] = temp[i];
        
        nums.resize(new_len);
        return new_len;
    }
};
