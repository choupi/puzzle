# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        p0 = head
        p1 = head
        while p1:
            if p1.next:
                p1 = p1.next.next
            else:
                return False
            p0 = p0.next
            if p0 == p1:
                return True
        return False
