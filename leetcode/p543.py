# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node):
        deep_l = 0
        max_l = 0
        deep_r = 0
        max_r = 0
        if node.left:
            deep_l, max_l = self.dfs(node.left)
            deep_l += 1
        if node.right:
            deep_r, max_r = self.dfs(node.right)
            deep_r += 1
        #print(node.val, deep_l, deep_r, max_l, max_r)
        return max(deep_l, deep_r), max(deep_l+deep_r, max_l, max_r)

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        _, max_path = self.dfs(root)
        return max_path
