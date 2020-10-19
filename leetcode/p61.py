# 61. Rotate List
# https://leetcode.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        n=0
        node=head
        while node:
            n+=1
            node=node.next
        if n<2: return head
        #print n
        k=k%n
        #print k
        if k==0: return head
        k=n-k-1
        node=head
        while k>0:
            node=node.next
            k-=1
        t=node
        #print t.val
        while node.next:
            node=node.next
        node.next=head
        head=t.next
        t.next=None
        return head
