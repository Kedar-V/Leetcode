class Solution:
    
    def twoSum(self, nums, req_sum, curr):
        
        hash_map = {}
        ans = []
        for i in range(len(nums)):
            
            if req_sum - nums[i] in hash_map:
                ans.append(sorted([curr, nums[i], req_sum - nums[i]]))
            else:
                hash_map[nums[i]] = True
                
        return ans
        
        
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        three_sum = []
        for i in range(len(nums)):
            
            ans = self.twoSum(nums[i+1:], 0 - nums[i], nums[i])
            
            for a in ans:
                if a in three_sum:
                    continue
                three_sum.append(a)
                
        return three_sum
            
            
