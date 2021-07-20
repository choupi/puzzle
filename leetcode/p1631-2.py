class Solution:
    def check_update(self, x0, y0, x1, y1):
        df = abs(self.heights[x0][y0] - self.heights[x1][y1])
        df = max(self.table[x0][y0], df)
        if df < self.table[x1][y1]:
            self.table[x1][y1] = df
            self.queue.append((x1, y1))
    
    def run_update(self, x, y):
        if x > 0:
            self.check_update(x, y, x-1, y)
        if y > 0:
            self.check_update(x, y, x, y-1)
        if x < len(self.heights) - 1:
            self.check_update(x, y, x+1, y)
        if y < len(self.heights[0]) - 1:
            self.check_update(x, y, x, y+1)
                
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        self.heights = heights
        self.table = [[float('inf')]*len(heights[0]) for i in range(len(heights))]
        self.table[len(heights)-1][len(heights[0])-1] = 0
        self.queue = [(len(heights)-1, len(heights[0])-1)]
        while self.queue:
            x, y = self.queue.pop(0)
            self.run_update(x, y)
        #print(self.table)
        return self.table[0][0]
