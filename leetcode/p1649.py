class Solution:
    def update(self, n):
        x = n
        while x<=self.max_n:
            self.BITs[x] += 1
            x += x & (-x)
    
    def query(self, n):
        x = n
        c = 0
        while x>0:
            c += self.BITs[x]
            x -= x & (-x)
        return c
    
    def createSortedArray(self, instructions: List[int]) -> int:
        self.max_n = 10**5
        self.BITs = [0] * (self.max_n + 1)
        cost = 0
        mm = 10**9 + 7
        for i, n in enumerate(instructions):
            cost += min(self.query(n-1), i-self.query(n))
            if cost > mm:
                cost -= mm
            self.update(n)
        return cost
