class Solution:
    def dfs(self, ind):
        if not self.num_set:
            self.total += 1
            return
        for n in list(self.num_set):
            if (not n % ind == 0) and (not ind % n == 0):
                continue
            self.num_set.remove(n)
            self.dfs(ind+1)
            self.num_set.add(n)
        return

    def countArrangement(self, n: int) -> int:
        self.num_set = set(range(1,n+1))
        self.total = 0
        self.dfs(1)
        return self.total
