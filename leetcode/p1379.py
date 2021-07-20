# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node):
        if node == self.target:
            self.clone_target = node
            self.clone_path = self.path[:]
            return
        if node.left:
            self.path.append('L')
            self.dfs(node.left)
            self.path.pop()
        if not self.clone_target and node.right:
            self.path.append('R')
            self.dfs(node.right)
            self.path.pop()
        return
    
    def trace(self, root):
        print(self.clone_path)
        node = root
        for i in range(len(self.clone_path)):
            node = node.left if self.clone_path[i]=='L' else node.right
        return node
    
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self.clone_target = None
        self.path = []
        self.target = target
        self.dfs(original)
        return self.trace(cloned)
