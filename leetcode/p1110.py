# 1110. Delete Nodes And Return Forest
# https://leetcode.com/problems/delete-nodes-and-return-forest/


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def BFS(self, root):
        q=[(root, None)]
        nodes=[]
        while q:
            n, p=q.pop()
            nodes.append((n,p))
            if n.left: q.append((n.left, n))
            if n.right: q.append((n.right, n))
        return reversed(nodes)
        
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        del_set=set(to_delete)
        nodes=self.BFS(root)
        trees=[]
        for n, p in nodes:
            if n.val not in del_set: continue
            if n.left: trees.append(n.left)
            if n.right: trees.append(n.right)
            #print p
            if p:
                if p.left==n: p.left=None
                if p.right==n: p.right=None
        if root.val not in del_set: trees.append(root)
        return trees
