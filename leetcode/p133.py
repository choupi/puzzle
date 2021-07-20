"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def copy(self, node):
        return Node(node.val)
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        visited = {}
        visited[node] = self.copy(node)
        node_queue = [node]
        while node_queue:
            n = node_queue.pop(0)
            if not n.neighbors:
                continue
            for nb in n.neighbors:
                if nb not in visited:
                    visited[nb] = self.copy(nb)
                    node_queue.append(nb)
                if visited[n].neighbors is None:
                    visited[n].neighbors = []
                visited[n].neighbors.append(visited[nb])
        return visited[node]
