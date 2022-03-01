class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
            
    #Using Hashing
#         hash_map = {}
        
#         for i in nums:
#             if i in hash_map:
#                 if hash_map[i] < 2:
#                     hash_map[i] += 1
#             else:
#                 hash_map[i] = 1
                
#         index = 0
#         k = 0
#         for key in sorted(hash_map.keys()):
#             for _ in range(hash_map[key]):
#                 nums[index] = key
#                 index += 1
#                 k += 1
#         return k
            
    #In O(1) Space
        prev = nums[0]
        index = 1
        curr_count = 1
        k = 1
        for i in range(1, len(nums)):
            curr = nums[i]
            if prev == curr:
                if curr_count < 2:
                    k += 1
                    curr_count += 1
                    nums[index] = nums[i]
                    index += 1
                                  
            else:
                k += 1
                curr_count = 1
                nums[index] = nums[i]
                index += 1 
            prev = curr
            
        return k
        
        
            
