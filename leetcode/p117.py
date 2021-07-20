"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def BFS(self, cursor):
        if len(self.node_queue) > 0:
            cursor.next = self.node_queue[0]
        if cursor.left:
            self.next_queue.append(cursor.left)
        if cursor.right:
            self.next_queue.append(cursor.right)

    def connect(self, root: 'Node') -> 'Node':
        if not root: return root
        self.node_queue = [root]
        self.next_queue = []
        self.root = root
        while len(self.node_queue)>0 or len(self.next_queue)>0:
            cursor = self.node_queue.pop(0)
            self.BFS(cursor)
            if len(self.node_queue)==0:
                self.node_queue = self.next_queue
                self.next_queue = []
        return self.root
