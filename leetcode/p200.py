# 200. Number of Islands
# https://leetcode.com/problems/number-of-islands/


class Solution(object):
    def find(self, i):
        stack=[]
        ni=i
        while self.disjoint[ni]!=ni:
            stack.append(ni)
            ni=self.disjoint[ni]
        s=ni
        for ni in stack: self.disjoint[ni]=s
        return s
    
    def join(self, i, j):
        si=self.find(i)
        sj=self.find(j)
        if i>j: self.disjoint[sj]=si
        else: self.disjoint[si]=sj
    
    def index(self, i, j):
        return self.n*i+j
    
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.m=len(grid)
        if self.m<1: return 0
        self.n=len(grid[0])
        self.disjoint=[i for i in range(self.m*self.n)]
        for i in range(self.m):
            for j in range(self.n):
                #print self.index(i,j)
                if grid[i][j]=='0':
                    self.disjoint[self.index(i,j)]=-1
                    continue
                if i>0 and grid[i-1][j]=='1': self.join(self.index(i-1,j), self.index(i,j))
                if j>0 and grid[i][j-1]=='1': self.join(self.index(i,j-1), self.index(i,j))
        dd={}
        for i in range(self.m*self.n):
            if self.disjoint[i]<0: continue
            si=self.find(i)
            dd[si]=dd.get(si, 0)+1
        #print self.disjoint
        return len(dd)
