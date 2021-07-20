# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = None
        cur = None
        offset = 0
        while l1 and l2:
            s = l1.val + l2.val + offset
            offset = 0
            if s > 9:
                s -= 10
                offset = 1
            t = ListNode(s)
            if head is None:
                head = t
            if cur:
                cur.next = t
            cur = t
            l1 = l1.next
            l2 = l2.next
        ll = None
        if l1:
            ll = l1
        elif l2:
            ll = l2
        while ll:
            s = ll.val + offset
            offset = 0
            if s > 9:
                s -= 10
                offset = 1
            t = ListNode(s)
            if head is None:
                head = t
            if cur:
                cur.next = t
            cur = t
            ll = ll.next
        if offset > 0:
            t = ListNode(offset)
            if cur:
                cur.next = t
        return head
