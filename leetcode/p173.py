# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.node_stack = []
        self.cursor = root
        self.DFS_left()

    def DFS_left(self):
        while self.cursor.left:
            self.node_stack.append(self.cursor)
            self.cursor = self.cursor.left

    def next(self) -> int:
        val = self.cursor.val
        if self.cursor.right:
            self.cursor = self.cursor.right
            self.DFS_left()
        elif len(self.node_stack) > 0:
            self.cursor = self.node_stack.pop()
        else:
            self.cursor = None
        return val

    def hasNext(self) -> bool:
        if self.cursor:
            return True
        return False


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
