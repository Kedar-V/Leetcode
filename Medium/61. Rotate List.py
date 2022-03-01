# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        
        if (not head or not head.next):
            return head
        
        heads = []
        curr = head
        length = 1
        
        while (curr.next):
            heads.append(curr)
            curr = curr.next
            length += 1
            
        heads.append(curr)
        curr.next = head
        
        index = length - k % length - 1
        heads[index].next = None
        
        if index == length - 1:
            return heads[0]
        
        return heads[index+1]
