# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, x, y):
        #print(root.val, x, y)
        if x not in self.coord:
            self.coord[x] = {}
        if y not in self.coord[x]:
            self.coord[x][y] = []
        self.coord[x][y].append(root.val)
        if root.left:
            self.dfs(root.left, x-1, y-1)
        if root.right:
            self.dfs(root.right, x+1, y-1)

    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        self.coord = {}
        self.dfs(root, 0, 0)
        res = []
        for x in sorted(self.coord.keys()):
            r = []
            for y in sorted(self.coord[x].keys(), reverse=True):
                r += sorted(self.coord[x][y])
            res.append(r)
        return res
