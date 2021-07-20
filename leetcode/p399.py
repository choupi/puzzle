class Solution:
    def BFS(self, start, end):
        if start not in self.eq_map or end not in self.eq_map:
            return -1
        bfs_visit = set()
        bfs_visit.add(start)
        bfs_queue = [(start, 1.0)]
        while bfs_queue:
            cursor, val = bfs_queue.pop(0)
            for k in self.eq_map[cursor]:
                if k == end:
                    return val*self.eq_map[cursor][k]
                if k not in bfs_visit:
                    bfs_visit.add(k)
                    bfs_queue.append((k, val*self.eq_map[cursor][k]))
        return -1
        
        
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        self.eq_map = {}
        for i, eq in enumerate(equations):
            if eq[0] not in self.eq_map:
                self.eq_map[eq[0]] = {}
            self.eq_map[eq[0]][eq[1]] = values[i]
            if eq[1] not in self.eq_map:
                self.eq_map[eq[1]] = {}
            self.eq_map[eq[1]][eq[0]] = 1.0 / values[i]
        return [self.BFS(eq[0], eq[1]) for eq in queries]
