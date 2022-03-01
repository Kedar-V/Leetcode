class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int middle;
        while (left <= right){
            
            middle = left + (right - left)/2;
            
            if (middle != 0 && nums[middle - 1] > nums[middle]){
                right = middle - 1;
            }
            
            else if (middle != n-1 && nums[middle + 1] > nums[middle]){
                left = middle + 1;
            }  
            else
                break;
        }
        return middle;
    }
};
