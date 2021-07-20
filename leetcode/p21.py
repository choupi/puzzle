# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = None
        if l1 and l2:
            if l1.val <= l2.val:
                res = l1
                l1 = l1.next
            else:
                res = l2
                l2 = l2.next
        elif l1:
            return l1
        elif l2:
            return l2
        else:
            return None
        cur = res
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        #print(cur)
        if l1:
            cur.next = l1
        elif l2:
            cur.next = l2
        return res
            
