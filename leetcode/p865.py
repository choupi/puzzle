# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deep(self, root, d):
        deep_left = 0
        deep_right = 0
        if root.left:
            deep_left, root_left = self.deep(root.left, d+1)
        if root.right:
            deep_right, root_right = self.deep(root.right, d+1)
        #print(deep_left, deep_right)
        if deep_left == deep_right:
            return deep_left + 1, root
        if deep_left > deep_right:
            return deep_left + 1, root_left
        if deep_left < deep_right:
            return deep_right + 1, root_right
        
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        depth, deep_root = self.deep(root, 0)
        return deep_root
