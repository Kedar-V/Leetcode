# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import random


class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head
        self.cache, self.n = self.cacheList()

    def cacheList(self):
        cache = {}
        curr = self.head
        count = 0
        while curr:
            cache[count] = curr.val
            curr = curr.next
            count += 1

        return cache, count   
    
    def getRandom(self) -> int:
        node = random.randint(0, self.n-1)
        return self.cache[node]


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
