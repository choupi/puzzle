# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        nodes = []
        n = head
        while n:
            nodes.append(n)
            n = n.next
        for i in range(len(nodes)):
            #print(i, nodes[i].val, len(nodes))
            if i % 2 == 0:
                if i < len(nodes) - 3:
                    nodes[i].next = nodes[i+3]
                elif i == len(nodes) - 3:
                    nodes[i].next = nodes[i+2]
                else:
                    nodes[i].next = None
            else:
                nodes[i].next = nodes[i-1]
            #print(nodes[i])
        if len(nodes)>1:
            return nodes[1]
        return head
