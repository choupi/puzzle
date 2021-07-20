# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def valid(self, root):
        if root.left:
            v, min_l, max_l = self.valid(root.left)
            if not v: return False, None, None
            if max_l >= root.val: return False, None, None
        else:
            min_l = root.val
            max_l = root.val
        if root.right:
            v, min_r, max_r = self.valid(root.right)
            if not v: return False, None, None
            if min_r <= root.val: return False, None, None
        else:
            min_r = root.val
            max_r = root.val
        return True, min_l, max_r
    
    def isValidBST(self, root: TreeNode) -> bool:
        v, _, _ = self.valid(root)
        return v
