# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        p1 = None
        p2 = None
        curr = head
        
        if (not curr):
            return head
        
        while (curr.next):
            p2 = curr.next
            curr.next = p1
            p1 = curr
            curr = p2
           
        curr.next = p1
        return curr
                 
