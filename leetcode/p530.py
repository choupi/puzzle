# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node):
        if node.left:
            self.dfs(node.left)
        self.nums.append(node.val)
        if node.right:
            self.dfs(node.right)
        return
    
    def getMinimumDifference(self, root: TreeNode) -> int:
        self.nums = []
        self.dfs(root)
        return min([self.nums[i+1] - self.nums[i] for i in range(len(self.nums)-1)])
