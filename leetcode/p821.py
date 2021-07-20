class Solution:
    def bfs(self, i):
        if i>0:
            if self.tab[i-1]>self.tab[i]+1:
                self.tab[i-1] = self.tab[i]+1
                self.queue.append(i-1)
        if i<len(self.tab)-1:
            if self.tab[i+1]>self.tab[i]+1:
                self.tab[i+1] = self.tab[i]+1
                self.queue.append(i+1)
    
    def shortestToChar(self, s: str, c: str) -> List[int]:
        self.tab = [float('inf')]*len(s)
        self.queue = [i for i in range(len(s)) if s[i]==c]
        for i in self.queue:
            self.tab[i] = 0
        while self.queue:
            i = self.queue.pop(0)
            self.bfs(i)
        return self.tab
