# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        p0 = head
        p1 = (head.next).next if head.next and (head.next).next else None
        p = 0
        while p0 and p1:
            if p0 == p1:
                return True
            p0 = p0.next
            p1 = (p1.next).next if p1.next and (p1.next).next else None
            p += 1
        return False
