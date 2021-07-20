# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        kheap = [(n.val, i) for i, n in enumerate(lists) if n]
        heapq.heapify(kheap)
        head = None
        res = None
        while kheap:
            val, i = heapq.heappop(kheap)
            if res:
                res.next = lists[i]
            else:
                head = lists[i]
            res = lists[i]
            if lists[i].next:
                lists[i] = lists[i].next
                heapq.heappush(kheap, (lists[i].val, i))
        return head
