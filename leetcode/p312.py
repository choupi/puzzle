class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        self.nums = [1] + nums + [1]
        self.len = len(self.nums)
        self.table = [[0] * self.len for _ in range(self.len)]
        for p in range(1, self.len):
            for i in range(self.len - p):
                j = i + p
                for k in range(i+1, j):
                    t = self.table[i][k] + self.table[k][j] + self.nums[i]*self.nums[k]*self.nums[j]
                    #print(i, j, k, t)
                    if t > self.table[i][j]:
                        self.table[i][j] = t
        #print(self.table)
        return self.table[0][self.len - 1]
