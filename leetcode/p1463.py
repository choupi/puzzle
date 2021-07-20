class Solution:
    def get_max(self, ir, j1, j2):
        m = 0
        if ir < self.nr -1:
            for j1d in range(max(0, j1-1), min(self.nc, j1+2)):
                for j2d in range(max(0, j2-1), min(self.nc, j2+2)):
                    if self.table[ir+1][j1d][j2d] > m:
                        m = self.table[ir+1][j1d][j2d]
        if j1 == j2:
            return m + self.grid[ir][j1]
        return m + self.grid[ir][j1] + self.grid[ir][j2]

    def cherryPickup(self, grid: List[List[int]]) -> int:
        self.nr = len(grid)
        self.nc = len(grid[0])
        self.grid = grid
        self.table = []
        for i in range(self.nr):
            self.table.append([[0]*self.nc for j in range(self.nc)])
        for i in range(self.nr):
            ir = self.nr - i - 1
            for j1 in range(self.nc):
                for j2 in range(self.nc):
                    self.table[ir][j1][j2] = self.get_max(ir, j1, j2)
        #print(self.table)
        return self.table[0][0][self.nc-1]

