# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    #def count_loop(self, p0):
    #    p = p0.next
    #    i = 1
    #    while p != p0:
    #        p = p.next
    #        i += 1
    #    return i

    def find_loop_start(self, head, p):
        p0 = head
        p1 = p
        while p0 != p1:
            p0 = p0.next
            p1 = p1.next
        return p0
    
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        p0 = head.next
        p1 = (head.next).next if head.next else None
        pi = 1
        while p0 and p1:
            if p0 == p1:
                #cnt = self.count_loop(p0)
                # 2*pi = t + k + n*cnt
                # pi = t + k + m*cnt
                # t + m*cnt = n*cnt - k
                #print(p0.val, p1.val)
                pp = self.find_loop_start(head, p1)
                #print(pi, pp.val)
                return pp
            p0 = p0.next
            p1 = (p1.next).next if p1.next and (p1.next).next else None
            pi += 1
        return None
