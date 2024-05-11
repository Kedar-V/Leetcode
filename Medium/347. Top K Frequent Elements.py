class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        hashmap = {}
        for num in nums:
            if num in hashmap:
                hashmap[num] += 1
            else:
                hashmap[num] = 1
        keys = dict(sorted(hashmap.items(), key=lambda x: (x[1], x[0]), reverse = True))
        return list(keys.keys())[:k]
        
