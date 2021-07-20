# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node):
        self.nodes.append(node)
        if not node.left and not node.right:
            nd = {}
            for n in self.nodes:
                nd[n.val] = nd.get(n.val, 0)+1
            c = 0
            for k, v in nd.items():
                if v%2 == 1:
                    c+=1
            if c < 2:
                self.count += 1
        if node.left:
            self.dfs(node.left)
        if node.right:
            self.dfs(node.right)
        self.nodes.pop(-1)
        
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.nodes = []
        self.count = 0
        self.dfs(root)
        return self.count
