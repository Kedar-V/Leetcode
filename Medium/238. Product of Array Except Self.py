class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        n = len(nums)
        left = [1 for _ in range(n)]
        right = [1 for _ in range(n)]

        for i in range(1, n):
            left[i] = left[i-1]*nums[i-1]
            right[i] = right[i-1]*nums[n-i]
        
        ans = []
        for i in range(n):
            ans.append(left[i] * right[n-i-1])

        return ans

        
