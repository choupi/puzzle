# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, path):
        if root.left is None and root.right is None:
            #print(path)
            self.total += int(''.join([str(p) for p in path+[root.val]]))
            return
        if root.left is not None:
            self.dfs(root.left, path+[root.val])
        if root.right is not None:
            self.dfs(root.right, path+[root.val])
        return
    
    def sumNumbers(self, root: TreeNode) -> int:
        self.total = 0
        if root is None:
            return 0
        self.dfs(root, [])
        return self.total
