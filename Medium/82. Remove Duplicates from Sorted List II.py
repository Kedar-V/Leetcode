# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        
        nums = []
        deleted = []
        curr = head
        
        while(curr):
            if curr.val in nums:
                deleted.append(curr.val)
                nums.remove(curr.val)
            else:
                if curr.val in deleted:
                    curr = curr.next
                    continue
                nums.append(curr.val)
            curr = curr.next
            
        if not nums:
            return None
        
        curr = head
        prev = curr
        for i in nums:
            curr.val = i
            prev = curr
            curr = curr.next
        if prev:
            prev.next = None
        return head
        
