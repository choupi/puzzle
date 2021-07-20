# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import random
class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        node = head
        cnt = 1
        while node.next:
            node = node.next
            cnt += 1
        node.next = head
        self.cursor = head
        self.count = cnt

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        cnt = random.randint(1, self.count)
        while cnt > 0:
            self.cursor = self.cursor.next
            cnt -= 1
        return self.cursor.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
