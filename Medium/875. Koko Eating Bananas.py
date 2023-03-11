import math

# Time Complexity = O(n * log(high))
class Solution:

    # O(n)
    def timeRequired(self, piles, k):
        time_to_eat = 0
        for pile in piles:
            time_to_eat += math.ceil(pile/k)
        
        return time_to_eat

    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        low = 1
        high = max(piles)
        min_mid = low + (high - low)//2
        ans = 0

        # O(log(high))
        while (low <= high):
            mid = low + (high - low)//2
            timeReq = self.timeRequired(piles, mid)
            print(low, mid, high, timeReq)
            # Need bigger k
            if timeReq > h:
                low = mid + 1
            
            else:
                ans = mid
                high = mid - 1


        return ans
