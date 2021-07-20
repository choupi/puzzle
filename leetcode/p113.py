# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def path(self, root, targetSum, paths):
        if root is None:
            return
        targetSum -= root.val
        if root.left is None and root.right is None:
            if targetSum == 0:
                self.path_list.append(paths+[root.val])
            return
        self.path(root.left, targetSum, paths+[root.val])
        self.path(root.right, targetSum, paths+[root.val])
        return
    
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        self.path_list = []
        self.path(root, targetSum, [])
        return self.path_list
