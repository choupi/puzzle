class NumArray:

    def __init__(self, nums: List[int]):
        self.nums_sum = []
        t = 0
        for n in nums:
            t += n
            self.nums_sum.append(t)

    def sumRange(self, i: int, j: int) -> int:
        if i > 0:
            return self.nums_sum[j] - self.nums_sum[i-1]
        else:
            return self.nums_sum[j]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
