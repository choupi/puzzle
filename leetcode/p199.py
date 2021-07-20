# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, depth):
        if len(self.rights)<depth+1:
            self.rights.append(node.val)
        else:
            self.rights[depth] = node.val
        if node.left:
            self.dfs(node.left, depth+1)
        if node.right:
            self.dfs(node.right, depth+1)

    def rightSideView(self, root: TreeNode) -> List[int]:
        self.rights = []
        if root:
            self.dfs(root, 0)
        return self.rights
        
