# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trim(self, node):
        if node is None:
            return None
        if node.val < self.low:
            #print('low', node.val, node.right)
            return self.trim(node.right)
        elif node.val > self.high:
            #print('high', node.val, node.left)
            return self.trim(node.left)
        node.left = self.trim(node.left)
        node.right = self.trim(node.right)
        return node
    
    def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
        self.low = low
        self.high = high
        root = self.trim(root)
        return root
