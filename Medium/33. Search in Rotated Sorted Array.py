class Solution:
    
    def helper(self, nums, target, left, right): 
        curr = int((left + right)/2)
        print(left, right, curr)
        
        # Base case
        if (left > right):
            return -1
        
        # Found
        if nums[curr] == target:
            return curr
            
#         # Ascending
#         if (nums[curr + 1] > nums[curr] and nums[curr - 1] < nums[curr]):
#             if nums[curr] > target:
#                 right = curr - 1
#             elif nums[curr] < target:
#                 left = curr + 1
        
        # Descending
        if (curr < len(nums)-1 and curr > 0 and nums[curr + 1] < nums[curr] and nums[curr - 1] < nums[curr]):
            print(curr)
            x = self.helper(nums, target, curr+1, right)
            y = self.helper(nums, target, left, curr-1)
            return max(x, y)
                
        # Pivot
        if (curr < len(nums)-1 and curr > 0 and nums[curr + 1] > nums[curr] and nums[curr - 1] > nums[curr]):
            # print('here')
            return max(self.helper(nums, target, curr+1, right), self.helper(nums, target, left, curr-1))
        
        # if nums[curr] > target:
        #     right = curr - 1
        # elif nums[curr] < target:
        #     left = curr + 1
        x = self.helper(nums, target, curr+1, right)
        y = self.helper(nums, target, left, curr-1)
        return max(x, y)
        
    def search(self, nums: List[int], target: int) -> int:  
        left = 0
        right = len(nums) - 1
        
        if len(nums) == 2:
            if nums[-1] == target:
                return 1
            if nums[0] == target:
                return 0
            return -1
        return self.helper(nums, target, left, right)
