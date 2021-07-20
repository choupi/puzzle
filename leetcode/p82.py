# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        nums = {}
        node = head
        while node:
            nums[node.val] = nums.get(node.val, 0) + 1
            node = node.next
        node = head
        last = None
        while node:
            while node and nums[node.val] > 1:
                node = node.next
            if not last:
                last = node
                head = last
            else:
                last.next = node
                last = node
            if node:
                node = node.next
        if last:
            last.next = None
        return head
