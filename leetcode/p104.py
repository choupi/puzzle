# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DFS(self, node, depth):
        if depth > self.max_depth:
            self.max_depth = depth
        if node.left:
            self.DFS(node.left, depth+1)
        if node.right:
            self.DFS(node.right, depth+1)

    def maxDepth(self, root: TreeNode) -> int:
        self.max_depth = 0
        if root:
            self.DFS(root, 1)
        return self.max_depth
