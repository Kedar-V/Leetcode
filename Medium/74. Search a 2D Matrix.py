class Solution:
    
    def binary_search(self, nums, val):
        
        n = len(nums)
        left = 0
        right = n - 1
        
        while(left <= right):
            
            mid = left + (right - left)//2
            
            if nums[mid] == val:
                return True
            
            elif nums[mid] < val:
                left = mid + 1
            
            else:
                right = mid - 1
        
        return False
        
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        flat = [j for row in matrix for j in row ]
        return self.binary_search(flat, target)
#         print(flat)
#         for row in matrix:
#             if self.binary_search(row, target):
#                 return True
            
#         return False
