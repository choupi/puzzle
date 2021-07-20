# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        l_balance = True
        l_depth = 0
        r_balance = True
        r_depth = 0
        root_balance = True
        if root.left:
            l_balance, l_depth = self.dfs(root.left)
        if root.right:
            r_balance, r_depth = self.dfs(root.right)
        if abs(l_depth - r_depth) > 1 or (not l_balance) or (not r_balance):
            root_balance = False
        return root_balance, max(l_depth, r_depth)+1
    
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        balance, _ = self.dfs(root)
        return balance
