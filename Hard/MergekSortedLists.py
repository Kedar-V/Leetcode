# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
''' 
O(N*log(k)) solution optimised using heap
'''
import heapq as hq
class Solution:

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        n = len(lists)
        heads = [head for head in lists if head]

        min_heads = [ (heads[i].val, i) for i in range(len(heads))]
        hq.heapify(min_heads)
        new_head = None
        ori_head = None

        while(True):
            if not min_heads:
                break

            min_index = hq.heappop(min_heads)[1]
            min_head = heads[min_index]

            if not new_head:
                new_head = ListNode(min_head.val)
                ori_head = new_head
            else:
                new_head.next = ListNode(min_head.val)
                new_head = new_head.next
            
            if heads[min_index].next:
                heads[min_index] = heads[min_index].next
                hq.heappush(min_heads, (heads[min_index].val, min_index))

        return ori_head

''' 
O(N*k) solution
'''
# class Solution:
#     def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

#         n = len(lists)
#         heads = [head for head in lists if head]

#         new_head = None
#         ori_head = None

#         while(True):
#             # print(heads)
#             if not heads:
#                 break

#             min_head = heads[0]
#             min_index = 0

#             for i in range(len(heads)):
#                 if heads[i].val < min_head.val:
#                     min_head = heads[i]
#                     min_index = i 

#             if not new_head:
#                 new_head = ListNode(min_head.val)
#                 ori_head = new_head
#             else:
#                 new_head.next = ListNode(min_head.val)
#                 new_head = new_head.next
            
#             if heads[min_index].next:
#                 heads[min_index] = heads[min_index].next
#             else:
#                 heads.pop(min_index)
              
#         # print(ori_head)
#         return ori_head

            

            




